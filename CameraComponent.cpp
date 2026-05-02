//
// Created by Binh Nguyen Thanh on 2/5/26.
//

#include "CameraComponent.h"

#include "Actor.h"
#include "Game.h"

CameraComponent::CameraComponent(Actor *actor, int updateOrder) : Component(actor, updateOrder) {
}

CameraComponent::~CameraComponent() {
}

void CameraComponent::SetViewMatrix(const Matrix4 &view) {
    mOwner->GetGame()->GetRenderer()->SetViewMatrix(view);
}
