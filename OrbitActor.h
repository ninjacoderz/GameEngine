//
// Created by Binh Nguyen Thanh on 2/5/26.
//

#ifndef ASTEROID_ORBITACTOR_H
#define ASTEROID_ORBITACTOR_H
#include "Actor.h"


class OrbitActor : public Actor{
    public:
        OrbitActor(class Game* game);
        void ActorInput(const struct InputState &state) override;
        void SetVisible(bool visible);
    private:
        class OrbitCameraComponent* mCameraComp;
        class MeshComponent* mMeshComp;
};


#endif //ASTEROID_ORBITACTOR_H