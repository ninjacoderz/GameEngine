//
// Created by Binh Nguyen Thanh on 25/4/26.
//

#ifndef ASTEROID_MESH_H
#define ASTEROID_MESH_H
#include <string>

#include "Texture.h"
#include "AsteroidGame/VertexArray.h"
#include <vector>

class Mesh {
public:
    Mesh();
    ~Mesh();
    bool Load(const std::string& fileName, class Game* game);
    void Unload();
    VertexArray* GetVertextArray() {
        return mVertexArray;
    }

    float GetRadius () const { return mRadius; }
    const std::string& GetShaderName () const { return mShaderName; }
    VertexArray* GetVertexArray() { return mVertexArray; }
    Texture* GetTexture(size_t index);

private:
    VertexArray* mVertexArray;
    std::vector<Texture*> mTextures;
    std::string mShaderName;
    float mRadius;
};


#endif //ASTEROID_MESH_H