//
// Created by Binh Nguyen Thanh on 26/4/26.
//

#include "MeshComponent.h"

#include "Actor.h"
#include "Game.h"

MeshComponent::MeshComponent(Actor* actor)
: Component(actor), mMesh(nullptr), mTextureIndex(0)  {
    mOwner->GetGame()->GetRenderer()->AddMeshComp(this);
}

MeshComponent::~MeshComponent() {
    mOwner->GetGame()->GetRenderer()->RemoveMeshComp(this);
}

void MeshComponent::Draw(Shader *shader) {
    if (mMesh) {
        shader->SetMatrixUniform("uWorldTransform", mOwner->GetWorldTransform());
        Texture* tex = mMesh->GetTexture(mTextureIndex);
        if (tex) tex->SetActive();
        VertexArray* vao = mMesh->GetVertexArray();
        vao->SetActive();
        glDrawElements(GL_TRIANGLES,
            vao->GetNumIndices(), GL_UNSIGNED_INT, nullptr);
    }
}

void MeshComponent::SetMesh(Mesh *mesh) {
    mMesh = mesh;
}

void MeshComponent::SetTextureIndex(int index) {
    mTextureIndex = index;
}
