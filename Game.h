// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include <SDL3/SDL.h>
#include <unordered_map>
#include <string>
#include <vector>

#include "Camera.h"
#include "Renderer.h"
#include "Texture.h"

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);
	
	Texture* GetTexture(const std::string& fileName);
	Renderer* GetRenderer() const { return mRenderer; }
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();

	// Map of textures loaded
	std::unordered_map<std::string, Texture*> mTextures;
	// All the actors in the game
	std::vector<class Actor*> mActors;
	// Any pending actors
	std::vector<class Actor*> mPendingActors;
	Uint32 mTicksCount;
	class InputSystem* mInputSystem;
	bool mIsRunning;
	// Track if we're updating actors right now
	bool mUpdatingActors;
	Renderer* mRenderer;
	Camera *mCamera;
};
