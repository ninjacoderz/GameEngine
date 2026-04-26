//
// Created by Binh Nguyen Thanh on 25/4/26.
//

#ifndef ASTEROID_RENDERER_H
#define ASTEROID_RENDERER_H
#include <unordered_map>
#include <SDL3/SDL.h>
#include "Mesh.h"
#include "MeshComponent.h"


class Renderer {
public:
    Renderer(class Game* game);
    ~Renderer();
    bool Initialize( float screenWidth, float screenHeight );
    void Shutdown();
    void UnloadData();
    void Draw();
    void AddMeshComp(MeshComponent* mesh);
    void RemoveMeshComp(MeshComponent* mesh);
    Texture* GetTexture(const std::string& textureName);
    Mesh* GetMesh(const std::string& meshName);
private:
    bool LoadShaders();
    void CreateSpriteVerts();
    Game* mGame;
    std::unordered_map<std::string, Mesh*> mMeshes;
    Shader* mMeshShader;
    std::vector<MeshComponent*> mMeshComps;
    Matrix4 mView;
    Matrix4 mProjection;
    float mScreenWidth, mScreenHeight;
};


#endif //ASTEROID_RENDERER_H