//
// Created by Binh Nguyen Thanh on 2/5/26.
//

#include "OrbitActor.h"
#include "Game.h"
#include "MeshComponent.h"
#include "OrbitCameraComponent.h"

OrbitActor::OrbitActor(class Game *game) : Actor(game) {
    mMeshComp = new MeshComponent(this);
    mMeshComp->SetMesh(game->GetRenderer()->GetMesh("Assets/RacingCar.gpmesh"));
    SetPosition(Vector3(0.0f, 0.0f, -100.0f));
    mCameraComp = new OrbitCameraComponent(this);
}

void OrbitActor::ActorInput(const struct InputState &state) {

    Vector2 mousePos = state.Mouse.GetPosition();
    bool buttonRightHeld = state.Mouse.GetButtonValue(SDL_BUTTON_RIGHT);
    const int maxMouseSpeed = 2;
    const float maxOrbitSpeed = Math::Pi;
    float yawSpeed = 0.0f;
    if ( mousePos.x != 0.0f ) {
        // Convert to ~[-1.0, 1.0]
        yawSpeed = mousePos.x / maxMouseSpeed;
        // Multiply by rotation/sec
        yawSpeed *= maxOrbitSpeed;
    }
    mCameraComp->SetYawSpeed(-yawSpeed);
    float pitchSpeed = 0.0f;
    if (mousePos.y != 0)
    {
        // Convert to ~[-1.0, 1.0]
        pitchSpeed = mousePos.y / maxMouseSpeed;
        pitchSpeed *= maxOrbitSpeed;
    }
    mCameraComp->SetPitchSpeed(pitchSpeed);
}

void OrbitActor::SetVisible(bool visible) {
    mMeshComp->SetVisible(visible);
}
