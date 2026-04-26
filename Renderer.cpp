//
// Created by Binh Nguyen Thanh on 25/4/26.
//

#include "Renderer.h"

#include <cassert>


Renderer::Renderer(Game *game)
: mGame(game)
, mMeshShader(nullptr)
, mScreenWidth(0)
, mScreenHeight(0) {
}

Renderer::~Renderer() {
}

bool Renderer::Initialize(float screenWidth, float screenHeight) {

    mScreenWidth = screenWidth;
    mScreenHeight = screenHeight;

    if (!LoadShaders())
    {
        SDL_Log("Failed to load shaders.");
        return false;
    }
    return true;
}

void Renderer::Draw() {
    // Set the clear color to light grey
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);

    mMeshShader->SetActive();
    mMeshShader->SetMatrixUniform("uViewProj", mView * mProjection);

    for (MeshComponent * mc: mMeshComps) {
        mc->Draw(mMeshShader);
    }
}

void Renderer::AddMeshComp(MeshComponent *mesh) {
    mMeshComps.push_back(mesh);
}

void Renderer::RemoveMeshComp(MeshComponent *mesh) {
    std::vector<MeshComponent*>::iterator it = std::find(mMeshComps.begin(), mMeshComps.end(), mesh);
    mMeshComps.erase(it);
}

Mesh* Renderer::GetMesh(const std::string &meshName) {
    Mesh* mesh = nullptr;
    auto iter = mMeshes.find(meshName);
    if (iter != mMeshes.end()) {
        mesh = iter->second;
        return mesh;
    }
    mesh = new Mesh();
    if (mesh->Load(meshName, this)) {
        mMeshes[meshName] = mesh;
        return mesh;
    }
    delete mesh;
    return nullptr;
}

bool Renderer::LoadShaders() {
    mMeshShader = new Shader();
    if (!mMeshShader->Load("Shaders/BasicMesh.vert", "Shaders/BasicMesh.frag")) {
        return false;
    }

    mMeshShader->SetActive();
    mView = Matrix4::CreateLookAt(Vector3::Zero, Vector3::UnitX, Vector3::UnitZ);
    mProjection = Matrix4::CreatePerspectiveFOV(Math::ToRadians(70.0f),
        mScreenWidth, mScreenHeight, 25.0f, 10000.0f);
    mMeshShader->SetMatrixUniform("uViewProj", mView * mProjection);
    return true;
}
