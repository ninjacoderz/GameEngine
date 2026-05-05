//
// Created by Binh Nguyen Thanh on 5/5/26.
//

#include "SplineActor.h"

#include "Game.h"
#include "MeshComponent.h"
#include "SplineCameraComponent.h"

SplineActor::SplineActor(class Game *game) : Actor(game) {
    MeshComponent* mc = new MeshComponent(this);
    mc->SetMesh(game->GetRenderer()->GetMesh("Assets/RacingCar.gpmesh"));
    SetPosition(Vector3(0.0f, 0.0f, -100.0f));

    mSplineCameraComp = new SplineCameraComponent(this);
    Spline path;
    path.mControlPoints.emplace_back(Vector3::Zero);
    for (int i = 0; i < 5; i++)
    {
        if (i % 2 == 0)
        {
            path.mControlPoints.emplace_back(Vector3(300.0f * (i + 1), 300.0f, 300.0f));
        }
        else
        {
            path.mControlPoints.emplace_back(Vector3(300.0f * (i + 1), 0.0f, 0.0f));
        }
    }

    mSplineCameraComp->SetSpline(path);
    mSplineCameraComp->SetPaused(false);
}

void SplineActor::ActorInput(const struct InputState &state)
{

}

void SplineActor::RestartSpline()
{
    mSplineCameraComp->Restart();
}
