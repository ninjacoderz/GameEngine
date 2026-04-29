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
#include "Math.h"

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
    if (!mRenderer -> Initialize(WINDOW_WIDTH, WINDOW_HEIGHT)) {
        SDL_Log("Failed to initialize Renderer");
        delete mRenderer;
        mRenderer = nullptr;
        return false;
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
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_QUIT:
                mIsRunning = false;
                break;
        }

        const bool keyState = SDL_GetKeyboardState(NULL);
        if (keyState && event.key.scancode == SDL_SCANCODE_ESCAPE) {
            mIsRunning = false;
        }

        mUpdatingActors = true;
        for (auto actor: mActors) {
            actor->ProcessInput(event);
        }
        mUpdatingActors = false;
    }
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
    Actor* a = new Actor(this);
    a->SetPosition(Vector3(200.0f, 75.0f, 0.0f));
    a->SetScale(100.0f);
    Quaternion q(Vector3::UnitY, -Math::PiOver2);
    q = Quaternion::Concatenate(q, Quaternion(Vector3::UnitZ, Math::Pi + Math::Pi / 4.0f));
    a->SetRotation(q);
    MeshComponent* mc = new MeshComponent(a);
    mc->SetMesh(mRenderer->GetMesh("Assets/Cube.gpmesh"));

    mRenderer->SetAmbientLight(Vector3(0.2f, 0.2f, 0.2f));
    DirectionalLight& dir = mRenderer->GetDirectionalLight();
    dir.mDirection = Vector3(0.0f, -0.707f, -0.707f);
    dir.mDiffuseColor = Vector3(0.78f, 0.88f, 1.0f);
    dir.mSpecColor = Vector3(0.8f, 0.8f, 0.8f);
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

void Game::AddSprite(SpriteComponent *sprite) {
    // Find the insertion point in the sorted vector
    // (The first element with a higher draw order than me)
    int myDrawOrder = sprite->GetDrawOrder();
    auto iter = mSprites.begin();
    for (;
        iter != mSprites.end();
        ++iter) {
        if (myDrawOrder < (*iter)->GetDrawOrder()) {
            break;
        }
    }

    // Inserts element before position of iterator
    mSprites.insert(iter, sprite);
}

void Game::RemoveSprite(SpriteComponent *sprite) {
    // (We can't swap because it ruins ordering)
    auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
    mSprites.erase(iter);
}
