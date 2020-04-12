#include "Surface.h"
#include <cassert>
#include <fstream>
#include "ChiliWin.h"

Surface::Surface(int width, int height)
	:width(width),
	height(height)
{
	pPixels = std::make_unique<Color[]>(width * height);
}

Surface::Surface(const std::string& fileName)
{
	ReadSurfaceFile(fileName);
}

Surface::Surface(Surface& surface)
	:Surface(surface.width, surface.height)
{
	pPixels = std::make_unique<Color[]>(width * height);
	for (int i = 0; i < width * height; i++) {
		pPixels[i] = surface.pPixels[i];
	}
}

Surface& Surface::operator=(const Surface& other)
{
	width = other.width;
	height = other.height;
	pPixels = std::make_unique<Color[]>(width * height);
	for (int i = 0; i < width * height; i++) {
		pPixels[i] = other.pPixels[i];
	}

	return *this;
}

void Surface::PutPixel(int x, int y, Color c)
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);


	auto pixelIndex = width * y + x;
	pPixels[pixelIndex] = c;
}

Color Surface::GetPixel(int x, int y) const
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);

	auto pixelIndex = width * y + x;
	return pPixels[pixelIndex];
}

int Surface::GetWidth() const
{
	return width;
}

int Surface::GetHeight() const
{
	return height;
}

RectI Surface::GetRect() const
{
	return RectI({ 0,0 }, width, height);
}

void Surface::ReadSurfaceFile(const std::string& fileName)
{
	std::ifstream file(fileName, std::ios::binary);
	assert(file);

	BITMAPFILEHEADER bmFileHeader;
	file.read(reinterpret_cast<char*>(&bmFileHeader), sizeof(bmFileHeader));

	BITMAPINFOHEADER bmInfoHeader;
	file.read(reinterpret_cast<char*>(&bmInfoHeader), sizeof(bmInfoHeader));

	assert((bmInfoHeader.biBitCount == 24) || (bmInfoHeader.biBitCount == 32));
	assert(bmInfoHeader.biCompression == BI_RGB);

	width = bmInfoHeader.biWidth;
	height = std::abs(bmInfoHeader.biHeight);
	pPixels = std::make_unique<Color[]>(width * height);

	file.seekg(bmFileHeader.bfOffBits);
	int numberOfColorsInPixel = bmInfoHeader.biBitCount / 3;
	auto filePadding = (4 - (width * 3) % 4) % 4;

	int dy = -1;
	int startY = height - 1;
	int endY = -1;
	if (bmInfoHeader.biHeight < 0) {
		dy = 1;
		startY = 0;
		endY = bmInfoHeader.biHeight;
	}

	for (int y = startY; y != endY; y = y + dy) {
		for (int x = 0; x < width; x++) {
			auto color = Color(file.get(), file.get(), file.get());
			PutPixel(x, y, color);

			if (bmInfoHeader.biBitCount == 32) {
				file.seekg(1, std::ios::cur);
			}
		}
		if (bmInfoHeader.biBitCount != 32) {
			file.seekg(filePadding, std::ios::cur);
		}
	}
}
