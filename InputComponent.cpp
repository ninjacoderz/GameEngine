// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "InputComponent.h"
#include "Actor.h"

InputComponent::InputComponent(class Actor* owner)
:MoveComponent(owner)
,mForwardKey(0)
,mBackKey(0)
,mClockwiseKey(0)
,mCounterClockwiseKey(0)
{
	
}

void InputComponent::ProcessInput(const SDL_Event& event)
{
	// Calculate forward speed for MoveComponent
	float forwardSpeed = 0.0f;
	const SDL_Scancode keyState = event.key.scancode;
	if (keyState == mForwardKey)
	{
		forwardSpeed += mMaxForwardSpeed;
	}
	if (keyState == mBackKey )
	{
		forwardSpeed -= mMaxForwardSpeed;
	}
	SetForwardSpeed(forwardSpeed);

	// Calculate angular speed for MoveComponent
	float angularSpeed = 0.0f;
	if (keyState == mClockwiseKey)
	{
		angularSpeed += mMaxAngularSpeed;
	}
	if (keyState == mCounterClockwiseKey)
	{
		angularSpeed -= mMaxAngularSpeed;
	}
	SetAngularSpeed(angularSpeed);
}
