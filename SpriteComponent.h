// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Component.h"
#include "Shader.h"
#include "Texture.h"
#include "SDL3/SDL.h"
class SpriteComponent : public Component
{
public:
	// (Lower draw order corresponds with further back)
	SpriteComponent(Actor* owner, int drawOrder = 100);
	~SpriteComponent();

	virtual void Draw(Shader* shader);
	virtual void SetTexture(Texture* texture);

	int GetDrawOrder() const { return mDrawOrder; }
	int GetTexHeight() const { return mTexHeight; }
	int GetTexWidth() const { return mTexWidth; }

	Texture* getTexture();
protected:
	Texture* mTexture;
	int mDrawOrder;
	float mTexWidth;
	float mTexHeight;
};
