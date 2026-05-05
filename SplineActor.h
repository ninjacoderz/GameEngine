//
// Created by Binh Nguyen Thanh on 5/5/26.
//

#ifndef ASTEROID_SPLINEACTOR_H
#define ASTEROID_SPLINEACTOR_H
#include "Actor.h"


class SplineActor :public Actor{
public:
    SplineActor(class Game* game);
    void ActorInput(const struct InputState &state) override;
    void RestartSpline();
private:
    class SplineCameraComponent* mSplineCameraComp;
};


#endif //ASTEROID_SPLINEACTOR_H