#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Colors.h"
#include "RectangleBox.h"

class Surface
{
public:
	Surface() = default;
	Surface(int width, int height);
	Surface(const std::string& fileName);
	Surface(Surface& surface);
	Surface(Surface&& surface) = default;
	Surface& operator=(const Surface& other);
	Surface& operator=(Surface&& other) = default;

	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;

	int GetWidth() const;
	int GetHeight() const;

	RectI GetRect() const;
private:
	void ReadSurfaceFile(const std::string& fileName);
private:
	std::unique_ptr<Color[]> pPixels;
	int width = 0;
	int height = 0;
};

