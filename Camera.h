//
// Created by Binh Nguyen Thanh on 30/4/26.
//

#ifndef ASTEROID_CAMERA_H
#define ASTEROID_CAMERA_H
#include "Actor.h"


class Camera: public Actor {
public:
    Camera(class Game* game);
    void Update(float deltaTime) override;
    void ActorInput(const struct InputState &state) override;
private:
    class MoveComponent* mMoveComp;
};


#endif //ASTEROID_CAMERA_H