#pragma once
#include "Colors.h"
#include "RectangleBox.h"
#include "Graphics.h"

namespace SpriteEffect
{
	class Chroma
	{
	public:
		Chroma(Color color)
			:chroma(color)
		{
		}
		void operator() (Color pixelColor, int xDest, int yDest, Graphics& gfx) {
			if (pixelColor != chroma) {
				gfx.PutPixel(xDest, yDest, pixelColor);
			}
		}
	private:
		Color chroma = Colors::Magenta;
	};


	class Substitution
	{
	public:
		Substitution(Color color, Color substitution)
			:chroma(color),
			substitution(substitution)
		{
		}
		void operator() (Color pixelColor, int xDest, int yDest, Graphics& gfx) {
			if (pixelColor != chroma) {
				gfx.PutPixel(xDest, yDest, substitution);
			}
		}
	private:
		Color chroma = Colors::Magenta;
		Color substitution;
	};


	class Copy
	{
	public:
		void operator() (Color pixelColor, int xDest, int yDest, Graphics& gfx) {
			gfx.PutPixel(xDest, yDest, pixelColor);
		}
	private:
	};


	class Ghost
	{
	public:
		Ghost(Color color)
			:chroma(color) 
		{
		}
		void operator() (Color pixelColor, int xDest, int yDest, Graphics& gfx) {
			if (pixelColor != chroma) {
				auto screenPixel = gfx.GetPixel(xDest, yDest);
				Color pixelBled = {
					unsigned char((screenPixel.GetR() + pixelColor.GetR()) / 2),
					unsigned char((screenPixel.GetG() + pixelColor.GetG()) / 2),
					unsigned char((screenPixel.GetB() + pixelColor.GetB()) / 2)
				};
				gfx.PutPixel(xDest, yDest, pixelBled);
			}
		}
	private:
		Color chroma = Colors::Magenta;
	};
}

