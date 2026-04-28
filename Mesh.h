//
// Created by Binh Nguyen Thanh on 25/4/26.
//

#ifndef ASTEROID_MESH_H
#define ASTEROID_MESH_H
#include <string>

#include "Texture.h"
#include "VertexArray.h"
#include <vector>

class Mesh {
public:
    Mesh();
    ~Mesh();
    bool Load(const std::string& fileName, class Renderer* renderer);
    void Unload();
    float GetRadius () const { return mRadius; }
    const std::string& GetShaderName () const { return mShaderName; }
    VertexArray* GetVertexArray() const { return mVertexArray; }
    Texture* GetTexture(size_t index) const;
    // Get specular power of mesh
    float GetSpecPower() const { return mSpecPower; }
private:
    VertexArray* mVertexArray;
    std::vector<Texture*> mTextures;
    std::string mShaderName;
    float mRadius;
    float mSpecPower;
};


#endif //ASTEROID_MESH_H