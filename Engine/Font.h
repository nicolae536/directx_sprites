#pragma once
#include "Colors.h"
#include <vector>
#include "RectangleBox.h"
#include "Surface.h"
#include "Graphics.h"
#include "Vector2d.h"

class Font
{
public:
	Font(std::string fileName, int rows, int columns);
	Font(std::string fileName, int rows, int columns, Color chroma, Color fontColor);
	void DrawText(Vector2d<int> position, std::string text, Graphics& gfx);
private:
	RectI MapChartToLetter(char c);
	void InitTextRects();
private:
	Color chroma = Colors::White;
	Color fontColor = Colors::White;
	std::vector<RectI> lettersList;
	char startChar = ' ';
	char endChar = '~';	
	Surface fontSurface;
	int rows;
	int columns;
	int letterWidth;
	int letterHeight;

};

