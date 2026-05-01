//
// Created by Binh Nguyen Thanh on 30/4/26.
//

#include "CameraActor.h"

#include "Game.h"
#include "MoveComponent.h"

void CameraActor::ActorInput(const struct InputState &state) {
    float forwardSpeed = 0.0f;
    float angularSpeed = 0.0f;
    // wasd movement
    if (state.Keyboard.GetKeyValue(SDL_SCANCODE_W))
    {
        forwardSpeed += 300.0f;
    }
    if (state.Keyboard.GetKeyValue(SDL_SCANCODE_S))
    {
        forwardSpeed -= 300.0f;
    }
    if (state.Keyboard.GetKeyValue(SDL_SCANCODE_A))
    {
        angularSpeed -= Math::TwoPi;
    }
    if (state.Keyboard.GetKeyValue(SDL_SCANCODE_D))
    {
        angularSpeed += Math::TwoPi;
    }

    mMoveComp->SetForwardSpeed(forwardSpeed);
    mMoveComp->SetAngularSpeed(angularSpeed);
}

CameraActor::CameraActor(class Game *game) : Actor(game) {
    mMoveComp = new MoveComponent(this);
}

void CameraActor::Update(float deltaTime) {
    Actor::Update(deltaTime);

    Vector3 cameraPos = GetPosition();
    Vector3 target = GetPosition() + GetForward();
    Vector3 up = Vector3::UnitZ;

    Matrix4 view = Matrix4::CreateLookAt(cameraPos, target, up);
    GetGame()->GetRenderer()->SetViewMatrix(view);
}
