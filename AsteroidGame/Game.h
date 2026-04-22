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

#include "Shader.h"
#include "Texture.h"
#include "VertexArray.h"
#include  "Ship.h"

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);
	
	Texture* GetTexture(const std::string& fileName);

	// Game-specific (add/remove asteroid)
	void AddAsteroid(class Asteroid* ast);
	void RemoveAsteroid(class Asteroid* ast);
	std::vector<class Asteroid*>& GetAsteroids() { return mAsteroids; }

	bool LoadShaders();
	Ship* GetShip() { return mShip; }
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();
	void InitSpriteVerts();

	void SetSpriteVertsActive();

	void SetSpriteShaderActive();

	// Map of textures loaded
	std::unordered_map<std::string, Texture*> mTextures;
	// All the actors in the game
	std::vector<class Actor*> mActors;
	// Any pending actors
	std::vector<class Actor*> mPendingActors;
	// All the sprite components drawn
	std::vector<class SpriteComponent*> mSprites;
	SDL_Window* mWindow;
	Uint32 mTicksCount;
	bool mIsRunning;
	// Track if we're updating actors right now
	bool mUpdatingActors;

	// Game-specific
	class Ship* mShip; // Player's ship
	std::vector<class Asteroid*> mAsteroids;

	SDL_GLContext mContext;

	VertexArray* mSpriteVertexArray;
	Shader* mSpriteShader;
};
