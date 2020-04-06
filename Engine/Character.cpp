#include "Character.h"

Character::Character(Vector2d<float> position, Vector2d<float> velocity,
	int width, int height,
	float sppedFactor, std::string spriteFile)
	: position(position),
	direction(velocity),
	sppedFactor(sppedFactor),
	width(width),
	height(height),
	surface(spriteFile)
{
	for (int i = 0; i < (int)Sequance::StandingLeft; i++) {
		animations.emplace_back(width, i * height, width, height, 4, surface, 0.1f, Colors::Magenta);
	}
	for (int i = (int)Sequance::StandingLeft; i < Sequance::Count; i++) {
		animations.emplace_back(0, (i - (int)Sequance::StandingLeft) * height, width, height, 1, surface, 0.1f, Colors::Magenta);
	}
	currentAnimation = Sequance::StandingBottom;
}

void Character::SetDirection(Vector2d<float> dir)
{
	if (dir.x < 0) {
		currentAnimation = Sequance::WalkingLeft;
	}
	else if (dir.x > 0) {
		currentAnimation = Sequance::WalkingRight;
	}
	else if (dir.y > 0)
	{
		currentAnimation = Sequance::WalkingBottom;
	}
	else if (dir.y < 0)
	{
		currentAnimation = Sequance::WalkingTop;
	}
	else
	{
		if (direction.x < 0) {
			currentAnimation = Sequance::StandingLeft;
		}
		else if (direction.x > 0) {
			currentAnimation = Sequance::StandingRight;
		}
		else if (direction.y > 0)
		{
			currentAnimation = Sequance::StandingBottom;
		}
		else if (direction.y < 0)
		{
			currentAnimation = Sequance::StandingUp;
		}
	}

	// For simplicity now
	direction = dir;
}

void Character::Update(float deltaTime)
{
	position += direction * sppedFactor;
	animations[currentAnimation].Update(deltaTime);

	if (showDamageEffect) {
		damageEffectTime += deltaTime;
		if (damageEffectTime > damageEffectDuration) {
			showDamageEffect = false;
		}
	}
}

void Character::ActivateDamadgeEffect()
{
	showDamageEffect = true;
	damageEffectTime = 0;
}

void Character::Draw(Graphics& gfx)
{
	if (showDamageEffect) {
		animations[currentAnimation].Draw(Vector2d<int>(position), gfx, Colors::Red);
	}
	else {
		animations[currentAnimation].Draw(Vector2d<int>(position), gfx);
	}
	
}
