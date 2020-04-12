#pragma once
#include "Surface.h"
#include <vector>
#include "Graphics.h"
#include "Vector2d.h"
#include "RectangleBox.h"
#include "Colors.h"
#include "SpriteEffect.h"

class Animation
{
public:
	Animation(int x, int y, int width, int height, int count,
		const Surface& sprite, float holdTime, Color chroma);
	void Draw(const Vector2d<int>& position, Graphics& gfx) const;
	void Draw(const Vector2d<int>& position, Graphics& gfx, RectI& clip) const;
	void Draw(const Vector2d<int>& position, Graphics& gfx, Color color) const;
	void Draw(const Vector2d<int>& position, Graphics& gfx, RectI& clip, Color charColor) const;
	void Update(float deltaTime);
private:
	void Advance();
private:
	const Surface& sprite;
	const Color chroma;
	std::vector<RectI> frames;
	int currentFrame = 0;
	float holdTime;
	float currentFrameTime = 0.0f;
};

