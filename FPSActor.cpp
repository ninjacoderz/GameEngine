//
// Created by Binh Nguyen Thanh on 1/5/26.
//

#include "FPSActor.h"

#include "FPSCameraComponent.h"
#include "Game.h"
#include "MeshComponent.h"
#include "MoveComponent.h"

FPSActor::FPSActor(class Game *game) : Actor(game) {
    mMoveComp = new MoveComponent(this);
    mCameraComp = new FPSCameraComponent(this);
    mFPSModel = new Actor(game);
    mMeshComp = new MeshComponent(mFPSModel);
    mMeshComp ->SetMesh(game->GetRenderer()->GetMesh("Assets/Rifle.gpmesh"));
}

void FPSActor::UpdateActor(float deltaTime) {
    Actor::UpdateActor(deltaTime);
    // We do the update sub Actor soon here

}

void FPSActor::ActorInput(const struct InputState &state) {
    Actor::ActorInput(state);

    float forwardSpeed = 0.0f;
    float strafeSpeed = 0.0f;
    // wasd movement
    if (state.Keyboard.GetKeyState(SDL_SCANCODE_W))
    {
        forwardSpeed += 400.0f;
    }
    if (state.Keyboard.GetKeyState(SDL_SCANCODE_S))
    {
        forwardSpeed -= 400.0f;
    }
    if (state.Keyboard.GetKeyState(SDL_SCANCODE_A))
    {
        strafeSpeed -= 400.0f;
    }
    if (state.Keyboard.GetKeyState(SDL_SCANCODE_D))
    {
        strafeSpeed += 400.0f;
    }

    mMoveComp->SetForwardSpeed(forwardSpeed);
    mMoveComp->SetStrafeSpeed(strafeSpeed);

    Vector2 mousePos = state.Mouse.GetPosition();
    angularSpeed = 0.0f;
    if (mousePos.x != 0.0f)
    {
        // Convert to ~[-1.0, 1.0]
        angularSpeed = mousePos.x / maxMouseSpeed;
        // Multiply by rotation/sec
        angularSpeed *= maxAngularSpeed;
    }
    mMoveComp->SetAngularSpeed(angularSpeed);

    // Compute pitch
    float pitchSpeed = 0.0f;
    if (mousePos.y != 0.0f)
    {
        // Convert to ~[-1.0, 1.0]
        pitchSpeed = mousePos.y / maxMouseSpeed;
        pitchSpeed *= maxPitchSpeed;
    }
    mCameraComp->SetPitchSpeed(pitchSpeed);

    // Update position of an FPS model relative to actor position
    const Vector3 modelOffset(Vector3(10.0f, 10.0f, -10.0f));
    Vector3 modelPos = GetPosition();
    modelPos += GetForward() * modelOffset.x;
    modelPos += GetRight() * modelOffset.y;
    modelPos.z += modelOffset.z;
    mFPSModel->SetPosition(modelPos);
    // Initialize rotation to actor rotation
    Quaternion q = GetRotation();
    // Rotate by pitch from the camera
    q = Quaternion::Concatenate(q,
    Quaternion(GetRight(), mCameraComp->GetPitch()));
    mFPSModel->SetRotation(q);
}

void FPSActor::SetVisible(bool visible)
{
    mMeshComp->SetVisible(visible);
}

FPSActor::~FPSActor() {
}
