//
// Created by Binh Nguyen Thanh on 2/5/26.
//

#include "FPSCameraComponent.h"

#include "Actor.h"

FPSCameraComponent::FPSCameraComponent(class Actor *actor, const int updateOrder) : CameraComponent(actor, updateOrder),
                                                                              mPitch(0),
                                                                              mPitchSpeed(0),
                                                                              maxPitch(Math::Pi / 3.0f) {
}

FPSCameraComponent::~FPSCameraComponent() {
}

void FPSCameraComponent::Update(float deltaTime) {
    CameraComponent::Update(deltaTime);

    Vector3 cameraPos = mOwner->GetPosition();
    mPitch += mPitchSpeed * deltaTime;
    mPitch = Math::Clamp(mPitch, -maxPitch, maxPitch);
    Quaternion quaternion(mOwner->GetRight(), mPitch);
    Vector3 viewForward = Vector3::Transform(mOwner->GetForward(), quaternion);
    Vector3 targetPos = cameraPos + viewForward * 100.0f;
    Vector3 up = Vector3::Transform(Vector3::UnitZ, quaternion);
    Matrix4 view = Matrix4::CreateLookAt(cameraPos, targetPos, up);

    SetViewMatrix(view);
}
