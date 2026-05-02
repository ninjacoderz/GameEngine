//
// Created by Binh Nguyen Thanh on 25/4/26.
//

#ifndef ASTEROID_RENDERER_H
#define ASTEROID_RENDERER_H
#include <unordered_map>
#include <SDL3/SDL.h>
#include "Mesh.h"
#include "MeshComponent.h"
#include "SpriteComponent.h"

struct DirectionalLight
{
    // Direction of light
    Vector3 mDirection;
    // Diffuse color
    Vector3 mDiffuseColor;
    // Specular color
    Vector3 mSpecColor;
};

class Renderer {
public:
    Renderer(class Game* game);
    ~Renderer();
    bool Initialize( float screenWidth, float screenHeight );
    void Shutdown();
    void UnloadData();

    void RemoveSprite(SpriteComponent *sprite);

    void Draw() const;
    void AddMeshComp(MeshComponent* mesh);
    void AddSpriteComp(SpriteComponent *spriteComp);
    void RemoveMeshComp(MeshComponent* mesh);
    Texture* GetTexture(const std::string& textureName);
    Mesh* GetMesh(const std::string& meshName);
    void SetAmbientLight(const Vector3& ambient) { mAmbientLight = ambient; }
    DirectionalLight& GetDirectionalLight() { return mDirLight; }
    void SetOpenGLAttributes();
    void SetViewMatrix(const Matrix4& view) { mView = view; }
    SDL_Window* GetWindow() const { return mWindow; }
private:
    bool LoadShaders();
    void SetLightUniforms(Shader *shader) const;

    void CreateSpriteVerts();


    Game* mGame;
    std::unordered_map<std::string, Mesh*> mMeshes;
    std::unordered_map<std::string, Texture*> mTextures;
    Shader* mMeshShader;
    std::vector<MeshComponent*> mMeshComps;
    Matrix4 mView;
    Matrix4 mProjection;
    Vector3 mAmbientLight;
    DirectionalLight mDirLight;
    float mScreenWidth, mScreenHeight;

    std::vector<SpriteComponent*> mSpriteComps;
    Shader* mSpriteShader;
    Matrix4 mSpriteViewProj;
    VertexArray* mSpriteVerts;
    // Window
    SDL_Window* mWindow;
    // OpenGL context
    SDL_GLContext mContext;
};


#endif //ASTEROID_RENDERER_H