//
// Created by Binh Nguyen Thanh on 25/4/26.
//

#ifndef ASTEROID_RENDERER_H
#define ASTEROID_RENDERER_H
#include "Mesh.h"
#include "SpriteComponent.h"


class Renderer {
public:
    Renderer();
    ~Renderer();
    bool Initialize( float screenWidth, float screenHeight );
    void Shutdown();
    void UnloadData();
    void Draw();
    void AddSprite(SpriteComponent* sprite);
    void RemoveSprite(SpriteComponent* sprite);
    Texture* GetTexture(const std::string& textureName);
    Mesh* GetMesh(const std::string& meshName);
private:
    bool LoadShaders();
    void CreateSpriteVerts();
};


#endif //ASTEROID_RENDERER_H