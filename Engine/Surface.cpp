#include "Surface.h"
#include <fstream>
#include "ChiliWin.h"

#define SURFACE_EXCEPTIONS( note ) Surface::Exception( _CRT_WIDE(__FILE__),__LINE__,note )


Surface::Surface(int width, int height)
	:width(width),
	height(height)
{
	auto totalSize = width * height;
	pPixels.resize(totalSize);
}

Surface::Surface(const std::string& fileName)
{
	ReadSurfaceFile(fileName);
}

Surface::Surface(Surface&& rhs) noexcept
{
	*this = std::move(rhs);
}

Surface& Surface::operator=(Surface&& rhs) noexcept
{
	width = rhs.width;
	height = rhs.height;
	pPixels = std::move(rhs.pPixels);
	rhs.width = 0;
	rhs.height = 0;
	return *this;
	// TODO: insert return statement here
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

	if (!file) {
		throw SURFACE_EXCEPTIONS(L"Failed to open file");
	}

	BITMAPFILEHEADER bmFileHeader;
	file.read(reinterpret_cast<char*>(&bmFileHeader), sizeof(bmFileHeader));

	BITMAPINFOHEADER bmInfoHeader;
	file.read(reinterpret_cast<char*>(&bmInfoHeader), sizeof(bmInfoHeader));

	if ((bmInfoHeader.biBitCount != 24) && (bmInfoHeader.biBitCount != 32)) {
		throw SURFACE_EXCEPTIONS(L"Invalid bitmap encodeing should be 24/32 bits");
	}
	if (bmInfoHeader.biCompression != BI_RGB) {
		throw SURFACE_EXCEPTIONS(L"Invalid bitmap compression should be: " + BI_RGB);
	}

	width = bmInfoHeader.biWidth;
	height = std::abs(bmInfoHeader.biHeight);
	auto totalSize = width * height;
	pPixels.resize(totalSize);

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
