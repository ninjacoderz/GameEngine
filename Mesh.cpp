//
// Created by Binh Nguyen Thanh on 25/4/26.
//

#include "Mesh.h"
#include <fstream>
#include <sstream>

#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>

#include "Renderer.h"
#include "SDL3/SDL_log.h"

Mesh::Mesh()
: mVertexArray(nullptr)
, mRadius(0)
, mSpecPower(100.0f){

}

Mesh::~Mesh() {
}

bool Mesh::Load(const std::string &fileName, Renderer *renderer) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        SDL_Log("Failed to open file %s", fileName.c_str());
        return false;
    }
    std::stringstream fileStream;
    fileStream << file.rdbuf();
    std::string contents = fileStream.str();
    rapidjson::StringStream jsonStr(contents.c_str());
    rapidjson::Document doc;
    doc.ParseStream(jsonStr);
    if (!doc.IsObject()) {
        SDL_Log("Failed to parse JSON file %s", fileName.c_str());
        return false;
    }

    int iter = doc["version"].GetInt();
    mShaderName = doc["shader"].GetString();

    size_t vertexSize = 8;
    const rapidjson::Value &textures = doc["textures"];
    if (!textures.IsArray() || textures.Size() < 1) {
        SDL_Log("Mesh %s has no textures, there should be at least one", fileName.c_str());
        return false;
    }
    mSpecPower = static_cast<float>(doc["specularPower"].GetDouble());
    for (rapidjson::SizeType i = 0; i < textures.Size(); i++) {
        std::string texName = textures[i].GetString();
        Texture* t = renderer->GetTexture(texName);
        if (t == nullptr) {
            t = renderer->GetTexture("Assets/Default.png");
        }
        mTextures.emplace_back(t);
    }

    const rapidjson::Value &vertsJson = doc["vertices"];
    if (!vertsJson.IsArray() || vertsJson.Size() < 1) {
        SDL_Log("Mesh %s has no vertices", fileName.c_str());
        return false;
    }

    std::vector<float> vertices;
    vertices.reserve(vertsJson.Size() * vertexSize);
    mRadius = 0.0f;
    for (rapidjson::SizeType i = 0; i < vertsJson.Size(); i++) {
        const rapidjson::Value& vert = vertsJson[i];
        if (!vert.IsArray() || vert.Size() != 8) {
            SDL_Log("Unexpected vertex format for %s", fileName.c_str());
            return false;
        }

        Vector3 pos(vert[0].GetDouble(), vert[1].GetDouble(), vert[2].GetDouble());
        mRadius = Math::Max(mRadius, pos.LengthSq());

        for (rapidjson::SizeType j = 0; j < vert.Size(); j++) {
            vertices.emplace_back(static_cast<float>(vert[j].GetDouble()));
        }
    }

    mRadius = Math::Sqrt(mRadius);

    const rapidjson::Value& indJson = doc["indices"];
    if (!indJson.IsArray() || indJson.Size() < 1) {
        SDL_Log("Mesh %s has no indices", fileName.c_str());
        return false;
    }
    std::vector<unsigned int> indices;
    indices.reserve(indJson.Size() * 3);
    for (rapidjson::SizeType i = 0; i < indJson.Size(); i++) {
        const rapidjson::Value &index = indJson[i];
        if (!index.IsArray() || index.Size() != 3) {
            SDL_Log("Invalid indices for %s", fileName.c_str());
            return false;
        }
        indices.emplace_back(index[0].GetUint());
        indices.emplace_back(index[1].GetUint());
        indices.emplace_back(index[2].GetUint());
    }

    // Now create a vertex array
    mVertexArray = new VertexArray(vertices.data(), static_cast<unsigned>(vertices.size()) / vertexSize,
        indices.data(), static_cast<unsigned>(indices.size()));
    return true;
}

void Mesh::Unload() {
    delete mVertexArray;
    mVertexArray = nullptr;
}

Texture * Mesh::GetTexture(size_t index) const {
    if (index < mTextures.size())
    {
        return mTextures[index];
    }
    return nullptr;
}
