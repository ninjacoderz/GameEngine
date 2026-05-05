// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include <SDL3_image/SDL_image.h>
#include "Game.h"
#include <algorithm>
#include "Actor.h"
#include "SpriteComponent.h"
#include "Random.h"
#include <GL/glew.h>

#include "FollowActor.h"
#include "FPSActor.h"
#include "InputSystem.h"
#include "Math.h"
#include "OrbitActor.h"
#include "PlaneActor.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

Game::Game()
    : mTicksCount(0), mIsRunning(true)
      , mUpdatingActors(false),
      mRenderer(nullptr) {
}

bool Game::Initialize() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != true) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    mRenderer = new Renderer(this);
    if (!mRenderer->Initialize(WINDOW_WIDTH, WINDOW_HEIGHT)) {
        SDL_Log("Failed to initialize Renderer");
        delete mRenderer;
        mRenderer = nullptr;
        return false;
    }

    mInputSystem = new InputSystem();
    mInputSystem->SetRelativeMouseMode(GetRenderer()->GetWindow(), true);
    if (!mInputSystem->Initialize()) {
        SDL_Log("Failed to initialize InputSystem");
        delete mInputSystem;
        mInputSystem = nullptr;
    }

    LoadData();

    mTicksCount = SDL_GetTicks();
    return true;
}

void Game::RunLoop() {
    while (mIsRunning) {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::ProcessInput() {

    mInputSystem->PrepareForUpdate();
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_QUIT:
                mIsRunning = false;
                break;
            case SDL_EVENT_MOUSE_WHEEL:
                mInputSystem->ProcessEvent(event);
                break;
            default:
                break;
        }
    }
    mInputSystem->Update();
    const InputState& inputState = mInputSystem->GetState();
    if (inputState.Keyboard.GetKeyState(SDL_SCANCODE_ESCAPE) == EReleased) {
        mIsRunning = false;
    }

    mUpdatingActors = true;
    for (auto actor: mActors) {
        actor->ProcessInput(inputState);
    }
    mUpdatingActors = false;
}

void Game::UpdateGame() {
    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;

    // Update all actors
    mUpdatingActors = true;
    for (auto actor: mActors) {
        actor->Update(deltaTime);
    }
    mUpdatingActors = false;

    // Move any pending actors to mActors
    for (auto pending: mPendingActors) {
        pending->ComputeWorldTransform();
        mActors.emplace_back(pending);
    }
    mPendingActors.clear();

    // Add any dead actors to a temp vector
    std::vector<Actor *> deadActors;
    for (auto actor: mActors) {
        if (actor->GetState() == Actor::EDead) {
            deadActors.emplace_back(actor);
        }
    }

    // Delete dead actors (which removes them from mActors)
    for (auto actor: deadActors) {
        delete actor;
    }

    mTicksCount = SDL_GetTicks();
}

void Game::GenerateOutput() {
    mRenderer->Draw();
}

void Game::LoadData() {
    // Actor *a = new Actor(this);
    // a->SetPosition(Vector3(200.0f, 75.0f, 0.0f));
    // a->SetScale(100.0f);
    // Quaternion q(Vector3::UnitY, -Math::PiOver2);
    // q = Quaternion::Concatenate(q, Quaternion(Vector3::UnitZ, Math::Pi + Math::Pi / 4.0f));
    // a->SetRotation(q);
    // MeshComponent *mc = new MeshComponent(a);
    // mc->SetMesh(mRenderer->GetMesh("Assets/Cube.gpmesh"));
    //
    // Actor* b = new Actor(this);
    // b->SetPosition(Vector3(200.0f, -75.0f, 0.0f));
    // b->SetScale(3.0f);
    // mc = new MeshComponent(b);
    // mc->SetMesh(mRenderer->GetMesh("Assets/Sphere.gpmesh"));

    // Setup floor
    Actor* a = new Actor(this);
    const float start = -1250.0f;
    const float size = 250.0f;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a = new PlaneActor(this);
            a->SetPosition(Vector3(start + i * size, start + j * size, -100.0f));
        }
    }

    Quaternion q = Quaternion(Vector3::UnitX, Math::PiOver2);
    for (int i = 0; i < 10; i++)
    {
        a = new PlaneActor(this);
        a->SetPosition(Vector3(start + i * size, start - size, 0.0f));
        a->SetRotation(q);

        a = new PlaneActor(this);
        a->SetPosition(Vector3(start + i * size, -start + size, 0.0f));
        a->SetRotation(q);
    }

    q = Quaternion::Concatenate(q, Quaternion(Vector3::UnitZ, Math::PiOver2));
    // Forward/back walls
    for (int i = 0; i < 10; i++)
    {
        a = new PlaneActor(this);
        a->SetPosition(Vector3(start - size, start + i * size, 0.0f));
        a->SetRotation(q);

        a = new PlaneActor(this);
        a->SetPosition(Vector3(-start + size, start + i * size, 0.0f));
        a->SetRotation(q);
    }

    // FPSActor* mFPSActor = new FPSActor(this);
    // OrbitActor* mOrbitActor = new OrbitActor(this);
    FollowActor* mFollowActor = new FollowActor(this);

    Actor* c = new Actor(this);
    c->SetPosition(Vector3(-350.0f, -350.0f, 0.0f));
    SpriteComponent* sc = new SpriteComponent(c);
    sc->SetTexture(mRenderer->GetTexture("Assets/HealthBar.png"));
}

void Game::UnloadData() {
    // Delete actors
    // Because ~Actor calls RemoveActor, have to use a different style loop
    while (!mActors.empty()) {
        delete mActors.back();
    }

    // Destroy textures
    for (auto i: mTextures) {
        i.second->Unload();
        delete i.second;
    }
    mTextures.clear();
}

Texture *Game::GetTexture(const std::string &fileName) {
    Texture *tex = nullptr;
    // Is the texture already in the map?
    auto iter = mTextures.find(fileName);
    if (iter != mTextures.end()) {
        tex = iter->second;
    } else {
        // Load from file
        tex = new Texture();
        if (tex->Load(fileName.c_str())) {
            mTextures.emplace(fileName, tex);
        } else {
            delete tex;
            tex = nullptr;
        }
    }
    return tex;
}

void Game::Shutdown() {
    UnloadData();
    SDL_Quit();
}

void Game::AddActor(Actor *actor) {
    // If we're updating actors, need to add to pending
    if (mUpdatingActors) {
        mPendingActors.emplace_back(actor);
    } else {
        mActors.emplace_back(actor);
    }
}

void Game::RemoveActor(Actor *actor) {
    // Is it in pending actors?
    auto iter = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
    if (iter != mPendingActors.end()) {
        // Swap to end of vector and pop off (avoid erase copies)
        std::iter_swap(iter, mPendingActors.end() - 1);
        mPendingActors.pop_back();
    }

    // Is it in actors?
    iter = std::find(mActors.begin(), mActors.end(), actor);
    if (iter != mActors.end()) {
        // Swap to end of vector and pop off (avoid erase copies)
        std::iter_swap(iter, mActors.end() - 1);
        mActors.pop_back();
    }
}
