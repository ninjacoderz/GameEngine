//
// Created by Binh Nguyen Thanh on 26/4/26.
//

#ifndef ASTEROID_MESHCOMPONENT_H
#define ASTEROID_MESHCOMPONENT_H
#include "Component.h"
#include "Mesh.h"
#include "Shader.h"


class MeshComponent : public Component{
public:
    MeshComponent(Actor* actor);
    ~MeshComponent() override;

    virtual void Draw(Shader* shader);
    virtual void SetMesh(Mesh* mesh);
    void SetTextureIndex(int index);

    void SetVisible(bool visible);
    bool GetVisible() const { return mVisible;}
protected:
    Mesh* mMesh;
    int mTextureIndex;
    bool mVisible;
};

#endif //ASTEROID_MESHCOMPONENT_H
