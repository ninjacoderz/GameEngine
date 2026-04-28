//
// Created by Binh Nguyen Thanh on 25/4/26.
//

#include "Renderer.h"
#include <SDL3/SDL.h>
#include <cassert>


Renderer::Renderer(Game *game)
: mGame(game)
, mMeshShader(nullptr){
}

Renderer::~Renderer() {
}

bool Renderer::Initialize(float screenWidth, float screenHeight) {

    mScreenWidth = screenWidth;
    mScreenHeight = screenHeight;

    SetOpenGLAttributes();

    // Setup OpenGL Window
    mWindow = SDL_CreateWindow("Game Programming in C++ (Chapter 6)", screenWidth, screenHeight, SDL_WINDOW_OPENGL);
    if (!mWindow) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }
    mContext = SDL_GL_CreateContext(mWindow);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        SDL_Log("Failed to initialize GLEW");
        return false;
    }
    glGetError();

    if (!LoadShaders())
    {
        SDL_Log("Failed to load shaders.");
        return false;
    }
    return true;
}

void Renderer::Shutdown() {
    mMeshShader->Unload();
    delete mMeshShader;
    mMeshShader = nullptr;

    SDL_GL_DestroyContext(mContext);
    SDL_DestroyWindow(mWindow);
}

void Renderer::UnloadData() {
    for (auto i: mTextures) {
        i.second->Unload();
    }
    mTextures.clear();

    for (auto i: mMeshes) {
        i.second->Unload();
        delete i.second;
    }
    mMeshes.clear();
}

void Renderer::Draw() const {
    // Set the clear color to light grey
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw mesh components
    // Enable depth buffering/disable alpha blend
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
    // Set the mesh shader active
    mMeshShader->SetActive();
    // Update view-projection matrix
    mMeshShader->SetMatrixUniform("uViewProj", mView * mProjection);
    // Update lighting uniforms
    SetLightUniforms(mMeshShader);
    for (auto mc : mMeshComps)
    {
        mc->Draw(mMeshShader);
    }

    // Swap the buffers
    SDL_GL_SwapWindow(mWindow);
}

void Renderer::AddMeshComp(MeshComponent *mesh) {
    mMeshComps.emplace_back(mesh);
}

void Renderer::RemoveMeshComp(MeshComponent *mesh) {
    std::vector<MeshComponent*>::iterator it = std::find(mMeshComps.begin(), mMeshComps.end(), mesh);
    mMeshComps.erase(it);
}

Texture * Renderer::GetTexture(const std::string &textureName) {
    Texture* tex = nullptr;
    auto iter = mTextures.find(textureName);
    if (iter != mTextures.end())
    {
        tex = iter->second;
    }
    else
    {
        tex = new Texture();
        if (tex->Load(textureName.c_str()))
        {
            mTextures.emplace(textureName, tex);
        }
        else
        {
            delete tex;
            tex = nullptr;
        }
    }
    return tex;
}

Mesh* Renderer::GetMesh(const std::string &fileName) {
    Mesh* m = nullptr;
    auto iter = mMeshes.find(fileName);
    if (iter != mMeshes.end())
    {
        m = iter->second;
    }
    else
    {
        m = new Mesh();
        if (m->Load(fileName, this))
        {
            mMeshes.emplace(fileName, m);
        }
        else
        {
            delete m;
            m = nullptr;
        }
    }
    return m;
}

void Renderer::SetOpenGLAttributes() {
    // Set OpenGL attributes
    // Use the core OpenGL profile
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    // Specify version 3.3
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    // Request a color buffer with 8-bits per RGBA channel
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    // Enable double buffering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    // Force OpenGL to use hardware acceleration
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
}

bool Renderer::LoadShaders() {

    // Create basic mesh shader
    mMeshShader = new Shader();
    if (!mMeshShader->Load("Shaders/Phong.vert", "Shaders/Phong.frag"))
    {
        return false;
    }

    mMeshShader->SetActive();
    // Set the view-projection matrix
    mView = Matrix4::CreateLookAt(Vector3::Zero, Vector3::UnitX, Vector3::UnitZ);
    mProjection = Matrix4::CreatePerspectiveFOV(Math::ToRadians(70.0f),
        mScreenWidth, mScreenHeight, 25.0f, 10000.0f);
    mMeshShader->SetMatrixUniform("uViewProj", mView * mProjection);
    return true;
}

void Renderer::SetLightUniforms(Shader *shader) const {
    Matrix4 invView = mView;
    invView.Invert();
    shader->SetVectorUniform("uCameraPos", invView.GetTranslation());
    shader->SetVectorUniform("uAmbientLight", mAmbientLight);
    shader->SetVectorUniform("uDirLight.mDirection", mDirLight.mDirection);
    shader->SetVectorUniform("uDirLight.mDiffuseColor", mDirLight.mDiffuseColor);
    shader->SetVectorUniform("uDirLight.mSpecColor", mDirLight.mSpecColor);
}