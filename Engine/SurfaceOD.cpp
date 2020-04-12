#include "Surface.h"
#include <cassert>

void Surface::PutPixel(int x, int y, Color c)
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);


	auto pixelIndex = width * y + x;
	pPixels.data()[pixelIndex] = c;
}

Color Surface::GetPixel(int x, int y) const
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);

	auto pixelIndex = width * y + x;
	return pPixels.data()[pixelIndex];
}

void Surface::Fill(Color c)
{
	std::fill(pPixels.begin(), pPixels.begin() + height * width, c);
}