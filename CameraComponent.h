//
// Created by Binh Nguyen Thanh on 2/5/26.
//

#ifndef ASTEROID_CAMERACOMPONENT_H
#define ASTEROID_CAMERACOMPONENT_H
#include "Component.h"
#include "Math.h"


class CameraComponent: public Component {
public:
    CameraComponent(Actor* actor, int updateOrder = 200);
    ~CameraComponent() override;
protected:
    void SetViewMatrix( const Matrix4& view);
};


#endif //ASTEROID_CAMERACOMPONENT_H