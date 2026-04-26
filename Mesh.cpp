//
// Created by Binh Nguyen Thanh on 25/4/26.
//

#include "Mesh.h"

Mesh::Mesh() : mVertexArray(nullptr), mRadius(0) {
}

Mesh::~Mesh() {
}

bool Mesh::Load(const std::string &fileName, Renderer *game) {
    return false;
}

void Mesh::Unload() {
}

Texture * Mesh::GetTexture(size_t index) {
    if (index < mTextures.size())
    {
        return mTextures[index];
    }
    return nullptr;
}
