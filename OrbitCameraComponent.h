//
// Created by Binh Nguyen Thanh on 2/5/26.
//

#ifndef ASTEROID_ORBITCAMERACOMPONENT_H
#define ASTEROID_ORBITCAMERACOMPONENT_H
#include "CameraComponent.h"


class OrbitCameraComponent : public CameraComponent{
    public:
        OrbitCameraComponent(class Actor* actor);
        void Update(float deltaTime) override;

        float GetPitchSpeed() const { return mPitchSpeed; }
        float GetYawSpeed() const { return mYawSpeed; }

        void SetPitchSpeed(float speed) { mPitchSpeed = speed; }
        void SetYawSpeed(float speed) { mYawSpeed = speed; }

    private:
        Vector3 mOffset;
        Vector3 mUp;
        float mPitchSpeed;
        float mYawSpeed;
};

#endif //ASTEROID_ORBITCAMERACOMPONENT_H