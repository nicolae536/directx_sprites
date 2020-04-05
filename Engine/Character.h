#pragma once
#include <string>
#include <vector>
#include "Vector2d.h"
#include "Animation.h"
#include "Surface.h"
#include "Graphics.h"

class Character
{
private:
	enum Sequance
	{
		WalkingLeft,
		WalkingRight,
		WalkingTop,
		WalkingBottom,
		StandingLeft,
		StandingRight,
		StandingUp,
		StandingBottom,
		Count
	};
public:
	Character(Vector2d<float> position, Vector2d<float> direction, 
		      float width, float height, 
		      float sppedFactor, std::string spriteFile);
	void SetDirection(Vector2d<float> dir);
	void Update(float deltaTime);
	void Draw(Graphics& gfx);
private:
	Vector2d<float> position;
	Vector2d<float> direction;
	float sppedFactor;
	float width;
	float height;
	Surface surface;
	std::vector<Animation> animations;
	int currentAnimation = 0;
};

