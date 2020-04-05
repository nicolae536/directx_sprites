#pragma once
#include <string>
#include "Colors.h"
#include "RectI.h"

class Surface
{
public:
	Surface(int width, int height);
	Surface(const std::string& fileName);
	Surface(const Surface& surface);
	Surface& operator=(const Surface& other);
	~Surface();

	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;

	int GetWidth() const;
	int GetHeight() const;

	RectI GetRect() const;
private:
	Color* pPixels = nullptr;
	int width;
	int height;
};

