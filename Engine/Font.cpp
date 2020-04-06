#include "Font.h"
#include <cassert>
#include "ChiliException.h"

Font::Font(std::string fileName, int rows, int columns)
	:fontSurface(fileName),
	rows(rows),
	columns(columns),
	letterWidth(fontSurface.GetWidth() / columns),
	letterHeight(fontSurface.GetHeight() / rows)
{
	InitTextRects();
}

Font::Font(std::string fileName, int rows, int columns, Color chroma, Color fontColor)
	:fontSurface(fileName),
	rows(rows),
	columns(columns),
	letterWidth(fontSurface.GetWidth() / columns),
	letterHeight(fontSurface.GetHeight() / rows),
	chroma(rows),
	fontColor(columns)
{
	InitTextRects();
}

void Font::DrawText(Vector2d<int> position, std::string text, Graphics& gfx)
{
	auto cursor = position;
	for (auto it : text) {
		if (it == '\n') {
			cursor.x = position.x;
			cursor.y += letterHeight;
		}
		else {
			auto textRect = MapChartToLetter(it);
			gfx.DrawSpriteSubstitute(cursor.x, cursor.y, textRect, fontSurface, chroma, fontColor);
			cursor.x += letterWidth;
		}
	}
}

RectI Font::MapChartToLetter(char c)
{
	if (c < startChar || c > endChar) {
		assert(false, "Cannot write character");
	}

	int charIndex = c - startChar;
	return lettersList[charIndex];
}

void Font::InitTextRects()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			lettersList.emplace_back(j * letterWidth, (j + 1) * letterWidth, i * letterHeight, (i + 1) * letterHeight);
		}
	}
}
