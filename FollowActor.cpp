//
// Created by Binh Nguyen Thanh on 5/5/26.
//

#include "FollowActor.h"

#include "Game.h"
#include "MeshComponent.h"
#include "MoveComponent.h"

FollowActor::FollowActor(class Game *game) : Actor(game) {
    mMeshComp = new MeshComponent(this);
    mMeshComp -> SetMesh(game->GetRenderer()->GetMesh("Assets/RacingCar.gpmesh"));
    SetPosition(Vector3(0.0f, 0.0f, -100.0f));

    mMoveComp = new MoveComponent(this);
    mCameraComp = new FollowCameraComponent(this);
    mCameraComp->SnapToIdeal();
}

void FollowActor::ActorInput(const struct InputState &state) {
    float forwardSpeed = 0.0f;
    float angularSpeed = 0.0f;

    if (state.Keyboard.GetKeyState(SDL_SCANCODE_W)) {
        forwardSpeed += 400.0f;
    }
    if (state.Keyboard.GetKeyState(SDL_SCANCODE_S)) {
        forwardSpeed -= 400.0f;
    }
    if (state.Keyboard.GetKeyState(SDL_SCANCODE_A)) {
        angularSpeed -= Math::Pi;
    }
    if (state.Keyboard.GetKeyState(SDL_SCANCODE_D)) {
        angularSpeed += Math::Pi;
    }

    mMoveComp->SetForwardSpeed(forwardSpeed);
    mMoveComp->SetAngularSpeed(angularSpeed);

    if (!Math::NearZero(forwardSpeed)) {
        mCameraComp -> SetHorzDist(500.0f);
    }
    else {
        mCameraComp -> SetHorzDist(100.0f);
    }
}

void FollowActor::SetVisible(bool visible) {
    mMeshComp->SetVisible(visible);
}

