#include "Animation.h"

Animation::Animation(int x, int y, int width, int height, int count, 
	const Surface& sprite, float holdTime, Color chroma)
	: sprite ( sprite ),
	holdTime( holdTime ),
	chroma( chroma )
{
	for (int i = 0; i < count; i++) {
		frames.emplace_back(x + i * width, x + (i + 1) * width, y, y + height);
	}
}

void Animation::Draw(const Vector2d<int>& position, Graphics& gfx) const
{

	gfx.DrawSprite(position.x, position.y, frames[currentFrame], gfx.GetScreenRect(), sprite, SpriteEffect::Ghost(chroma));
}

void Animation::Draw(const Vector2d<int>& position, Graphics& gfx, RectI& clip) const
{
	gfx.DrawSprite(position.x, position.y, frames[currentFrame], clip, sprite, SpriteEffect::Copy());
}

void Animation::Draw(const Vector2d<int>& position, Graphics& gfx, RectI& clip, Color color) const
{
	gfx.DrawSprite(position.x, position.y, frames[currentFrame], clip, sprite, SpriteEffect::Substitution(chroma, color));
}

void Animation::Draw(const Vector2d<int>& position, Graphics& gfx, Color color) const
{
	gfx.DrawSprite(position.x, position.y, frames[currentFrame], sprite, SpriteEffect::Substitution(chroma, color));
}

void Animation::Update(float deltaTime)
{
	currentFrameTime += deltaTime;
	while (currentFrameTime > holdTime)
	{
		Advance();
		currentFrameTime -= holdTime;
	}	
}

void Animation::Advance()
{
	currentFrame++;
	if (currentFrame >= frames.size()) {
		currentFrame = 0;
	}
}
