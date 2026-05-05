//
// Created by Binh Nguyen Thanh on 25/4/26.
//

#include "Renderer.h"
#include <SDL3/SDL.h>
#include <cassert>

#include "SpriteComponent.h"

const Vector3 DEFAULT_EMBIENTLIGHT = Vector3(0.2f, 0.2f, 0.2f);
const Vector3 DEFAULT_DIRLIGHT = Vector3(0.0f, -0.707f, -0.707f);
const Vector3 DEFAULT_DIFFUSECOLOR = Vector3(0.0f, 1.0f, 1.0f);
const Vector3 DEFAULT_SPECLIGHT = Vector3(0.8f, 0.8f, 0.8f);

Renderer::Renderer(Game *game)
    : mGame(game)
      , mMeshShader(nullptr)
      , mSpriteShader(nullptr)
      , mSpriteVerts(nullptr)
      , mScreenWidth(0)
      , mScreenHeight(0)
      , mWindow(nullptr)
      , mContext(nullptr) {
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

    if (!LoadShaders()) {
        SDL_Log("Failed to load shaders.");
        return false;
    }

    // Setup Light
    SetAmbientLight(DEFAULT_EMBIENTLIGHT);
    DirectionalLight &dir = GetDirectionalLight();
    dir.mDirection = DEFAULT_DIRLIGHT;
    dir.mDiffuseColor = DEFAULT_DIFFUSECOLOR;
    dir.mSpecColor = DEFAULT_SPECLIGHT;

    CreateSpriteVerts();

    return true;
}


void Renderer::Shutdown() {
    delete mSpriteVerts;
    mSpriteVerts = nullptr;

    mSpriteShader->Unload();
    delete mSpriteShader;
    mSpriteShader = nullptr;

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

void Renderer::RemoveSprite(SpriteComponent *sprite) {
    auto it = std::find(mSpriteComps.begin(), mSpriteComps.end(), sprite);
    if (it != mSpriteComps.end()) mSpriteComps.erase(it);
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
    for (auto mc: mMeshComps) {
        if (mc->GetVisible())
        {
            mc->Draw(mMeshShader);
        }
    }

    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendEquationSeparate(GL_FUNC_ADD, GL_FUNC_ADD);
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);
    mSpriteShader->SetActive();
    mSpriteVerts->SetActive();
    for (auto sprite: mSpriteComps) {
        sprite->Draw(mSpriteShader);
    }
    // Swap the buffers
    SDL_GL_SwapWindow(mWindow);
}

void Renderer::AddMeshComp(MeshComponent *mesh) {
    mMeshComps.emplace_back(mesh);
}

void Renderer::AddSpriteComp(SpriteComponent* spriteComp) {
    mSpriteComps.emplace_back(spriteComp);
}
void Renderer::RemoveMeshComp(MeshComponent *mesh) {
    std::vector<MeshComponent *>::iterator it = std::find(mMeshComps.begin(), mMeshComps.end(), mesh);
    if (it != mMeshComps.end()) mMeshComps.erase(it);
}

Texture *Renderer::GetTexture(const std::string &textureName) {
    Texture *tex = nullptr;
    auto iter = mTextures.find(textureName);
    if (iter != mTextures.end()) {
        tex = iter->second;
    } else {
        tex = new Texture();
        if (tex->Load(textureName.c_str())) {
            mTextures.emplace(textureName, tex);
        } else {
            delete tex;
            tex = nullptr;
        }
    }
    return tex;
}

Mesh *Renderer::GetMesh(const std::string &fileName) {
    Mesh *m = nullptr;
    auto iter = mMeshes.find(fileName);
    if (iter != mMeshes.end()) {
        m = iter->second;
    } else {
        m = new Mesh();
        if (m->Load(fileName, this)) {
            mMeshes.emplace(fileName, m);
        } else {
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

Vector3 Renderer::Unproject(const Vector3 &screenPoint) {
    // Convert screenPoint to device coordinates (between -1 and +1)
    Vector3 deviceCoord = screenPoint;
    deviceCoord.x /= (mScreenWidth) * 0.5f;
    deviceCoord.y /= (mScreenHeight) * 0.5f;
    // Transform vector by unprojection matrix
    Matrix4 unprojection = mView * mProjection;
    unprojection.Invert();
    return Vector3::TransformWithPerspDiv(deviceCoord, unprojection);
}

void Renderer::GetScreenDirection(Vector3 &outStart, Vector3 &outDir) {
    // Get start point (in center of screen on near plane)
    Vector3 screenPoint(0.0f, 0.0f, 0.0f);
    outStart = Unproject(screenPoint);
    // Get end point (in center of screen, between near and far)
    screenPoint.z = 0.9f;
    Vector3 end = Unproject(screenPoint);
    // Get direction vector
    outDir = end - outStart;
    outDir.Normalize();
}

bool Renderer::LoadShaders() {
    mSpriteShader = new Shader();
    if (!mSpriteShader->Load("Shaders/Sprite.vert", "Shaders/Sprite.frag"))
    {
        return false;
    }

    mSpriteShader->SetActive();
    // Set the view-projection matrix
    Matrix4 viewProj = Matrix4::CreateSimpleViewProj(mScreenWidth, mScreenHeight);
    mSpriteShader->SetMatrixUniform("uViewProj", viewProj);

    // Create a basic mesh shader
    mMeshShader = new Shader();
    if (!mMeshShader->Load("Shaders/Phong.vert", "Shaders/Phong.frag")) {
        return false;
    }
    // Set the view-projection matrix
    mView = Matrix4::CreateLookAt(Vector3::Zero, Vector3::UnitX, Vector3::UnitZ);
    mProjection = Matrix4::CreatePerspectiveFOV(Math::ToRadians(70.0f),
                                                mScreenWidth, mScreenHeight, 25.0f, 10000.0f);
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

void Renderer::CreateSpriteVerts()
{
    float vertices[] = {
        -0.5f, 0.5f, 0.f, 0.f, 0.f, 0.0f, 0.f, 0.f, // top left
        0.5f, 0.5f, 0.f, 0.f, 0.f, 0.0f, 1.f, 0.f, // top right
        0.5f,-0.5f, 0.f, 0.f, 0.f, 0.0f, 1.f, 1.f, // bottom right
        -0.5f,-0.5f, 0.f, 0.f, 0.f, 0.0f, 0.f, 1.f  // bottom left
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    mSpriteVerts = new VertexArray(vertices, 4, indices, 6);
}