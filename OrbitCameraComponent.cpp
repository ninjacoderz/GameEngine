//
// Created by Binh Nguyen Thanh on 2/5/26.
//

#include "OrbitCameraComponent.h"

#include "Actor.h"

OrbitCameraComponent::OrbitCameraComponent(class Actor *actor)
: CameraComponent(actor)
, mOffset(-400.0f, 0.0f, 0.0f)
, mUp(Vector3::UnitZ)
, mPitchSpeed(0)
, mYawSpeed(0) {
}

void OrbitCameraComponent::Update(float deltaTime) {
    CameraComponent::Update(deltaTime);

    Quaternion yaw(Vector3::UnitZ, mYawSpeed * deltaTime);
    mOffset = Vector3::Transform(mOffset, yaw);
    mUp = Vector3::Transform(mUp, yaw);

    Vector3 forward = -1.0f * mOffset;
    forward.Normalize();
    Vector3 right = Vector3::Cross(mUp, forward);
    right.Normalize();

    Quaternion pitch(right, mPitchSpeed * deltaTime);
    mOffset = Vector3::Transform(mOffset, pitch);
    mUp = Vector3::Transform(mUp, pitch);

    Vector3 target = mOwner->GetPosition();
    Vector3 camaraPos = target + mOffset;
    Matrix4 view = Matrix4::CreateLookAt(camaraPos, target, mUp);
    SetViewMatrix(view);

}
