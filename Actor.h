// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include <vector>
#include "Math.h"
#include <cstdint>

#include "SDL3/SDL_events.h"
#include "SDL3/SDL_scancode.h"

class Actor
{
public:
	enum State
	{
		EActive,
		EPaused,
		EDead
	};

	Actor(class Game* game);
	virtual ~Actor();

	// Update function called from Game (not overridable)
	void Update(float deltaTime);
	// Updates all the components attached to the actor (not overridable)
	void UpdateComponents(float deltaTime);
	// Any actor-specific update code (overridable)
	virtual void UpdateActor(float deltaTime);

	// ProcessInput function called from Game (not overridable)
	void ProcessInput(const SDL_Event &event);
	// Any actor-specific input code (overridable)
	virtual void ActorInput(const SDL_Event& event);

	// Getters/setters
	const Vector3& GetPosition() const { return mPosition; }
	void SetPosition(const Vector3& pos) { mPosition = pos; mRecomputeWorldTransform = true;}
	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; mRecomputeWorldTransform = true;}
	Quaternion GetRotation() const { return mRotation; }
	void SetRotation(Quaternion rotation) { mRotation = rotation; mRecomputeWorldTransform = true;}

	Vector3 GetForward() const { return Vector3::Transform(Vector3::UnitX, mRotation); }

	State GetState() const { return mState; }
	void SetState(State state) { mState = state; }

	Game* GetGame() const { return mGame; }

	// Add/remove components
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

	void ComputeWorldTransform();
	Matrix4 GetWorldTransform() const { return mWorldTransform; }
private:
	// Actor's state
	State mState;

	// Transform
	Vector3 mPosition;
	Quaternion mRotation;
	float mScale;

	std::vector<class Component*> mComponents;
	Game* mGame;

	Matrix4 mWorldTransform;
	bool mRecomputeWorldTransform;

};
