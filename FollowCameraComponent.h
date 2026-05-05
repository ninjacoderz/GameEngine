//
// Created by Binh Nguyen Thanh on 5/5/26.
//

#ifndef ASTEROID_FOLLOWCAMERACOMPONENT_H
#define ASTEROID_FOLLOWCAMERACOMPONENT_H
#include "CameraComponent.h"


class FollowCameraComponent : public CameraComponent {
public:
    FollowCameraComponent(class Actor* actor);

    void Update(float deltaTime) override;
    void SnapToIdeal();

    void SetHorzDist(float dist) { mHorzDist = dist; }
    void SetVertDist(float dist) { mVertDist = dist; }
    void SetTargetDist(float dist) { mTargetDist = dist; }
    void SetSpringConstant(float springConstant) { mSpringConstant = springConstant; }
private:

    Vector3 ComputeCameraPos() const;
    Vector3 mActualPos;
    Vector3 mVelocity;
    float mHorzDist;
    float mVertDist;
    float mTargetDist;
    float mSpringConstant;
};



#endif //ASTEROID_FOLLOWCAMERACOMPONENT_H