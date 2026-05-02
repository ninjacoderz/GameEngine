//
// Created by Binh Nguyen Thanh on 2/5/26.
//

#ifndef ASTEROID_FPSCAMERACOMPONENT_H
#define ASTEROID_FPSCAMERACOMPONENT_H
#include "CameraComponent.h"

class FPSCameraComponent: public CameraComponent{
public:
    FPSCameraComponent(class Actor* actor, int updateOrder = 200);
    ~FPSCameraComponent();

    void Update(float deltaTime) override;

    float GetPitch() const { return mPitch; }
    void SetPitch(float pitch) { mPitch = pitch; }
    void SetPitchSpeed(float speed) { mPitchSpeed = speed; }
    void SetMaxPitch(float mMaxPitch) { this->maxPitch = mMaxPitch; }
    float GetMaxPitch() const { return maxPitch; }
    float GetPitchSpeed() const { return mPitchSpeed; }
private:
    float mPitch;
    float mPitchSpeed;
    float maxPitch;
};


#endif //ASTEROID_FPSCAMERACOMPONENT_H