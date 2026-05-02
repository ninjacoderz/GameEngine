//
// Created by Binh Nguyen Thanh on 1/5/26.
//

#ifndef ASTEROID_FPSACTOR_H
#define ASTEROID_FPSACTOR_H
#include "Actor.h"


class FPSActor : public Actor{
public:
    FPSActor(class Game* game);
    ~FPSActor() override;

    void UpdateActor(float deltaTime) override;
    void ActorInput(const struct InputState &state) override;
    void SetVisible(bool visible);
private:
    class MoveComponent* mMoveComp;
    class MeshComponent* mMeshComp;
    class FPSCameraComponent* mCameraComp;
    class Actor* mFPSModel;

    int maxMouseSpeed = 10;
    float maxAngularSpeed = Math::Pi * 8;
    float maxPitchSpeed = Math::Pi * 8;
    float angularSpeed = 0.0f;
};

#endif //ASTEROID_FPSACTOR_H