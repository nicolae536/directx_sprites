#define GOD_GRAPHICS
#include "Graphics.h"

void Graphics::BeginFrame()
{
	// clear the sysbuffer
	memset(pSysBuffer, 0u, sizeof(Color) * Graphics::ScreenHeight * Graphics::ScreenWidth);
}

void Graphics::PutPixel(int x, int y, Color c)
{
	assert(x >= 0);
	assert(x < int(Graphics::ScreenWidth));
	assert(y >= 0);
	assert(y < int(Graphics::ScreenHeight));
	pSysBuffer[Graphics::ScreenWidth * y + x] = c;
}

Color Graphics::GetPixel(int x, int y) const
{
	assert(x >= 0);
	assert(x < int(Graphics::ScreenWidth));
	assert(y >= 0);
	assert(y < int(Graphics::ScreenHeight));
	return pSysBuffer[Graphics::ScreenWidth * y + x];
}

template
void Graphics::DrawSprite<SpriteEffect::Copy>(int x, int y, RectI srcRect, const RectI& clip, const Surface& s, SpriteEffect::Copy effect);
template
void Graphics::DrawSprite<SpriteEffect::Chroma>(int x, int y, RectI srcRect, const RectI& clip, const Surface& s, SpriteEffect::Chroma effect);
template
void Graphics::DrawSprite<SpriteEffect::Substitution>(int x, int y, RectI srcRect, const RectI& clip, const Surface& s, SpriteEffect::Substitution effect);
template
void Graphics::DrawSprite<SpriteEffect::Ghost>(int x, int y, RectI srcRect, const RectI& clip, const Surface& s, SpriteEffect::Ghost effect);