//
// Created by Binh Nguyen Thanh on 5/5/26.
//

#ifndef ASTEROID_FOLLOWACTOR_H
#define ASTEROID_FOLLOWACTOR_H
#include "Actor.h"
#include "FollowCameraComponent.h"


class FollowActor : public Actor{
public:
    FollowActor(class Game* game);
    void ActorInput(const struct InputState &state) override;
    void SetVisible(bool visible);
private:
    FollowCameraComponent* mCameraComp;
    class MeshComponent* mMeshComp;
    class MoveComponent* mMoveComp;
};


#endif //ASTEROID_FOLLOWACTOR_H