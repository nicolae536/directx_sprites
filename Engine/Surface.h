#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Colors.h"
#include "RectangleBox.h"
#include "ChiliException.h"

class Surface
{
public:
	class Exception : ChiliException {
	public:
		Exception(const wchar_t* file, unsigned int line, const std::wstring& note = L"")
			: ChiliException(file, line, note)
		{}
		std::wstring GetFullMessage() const override {
			return L"Line: " + std::to_wstring(GetLine()) + L"\n" + L"Message" + GetNote();
		};
		std::wstring GetExceptionType() const override {
			return L"class Surface::Exception";
		};
	};
public:
	Surface() = default;
	Surface(int width, int height);
	Surface(const std::string& fileName);
	Surface(Surface& surface) = default;
	Surface(Surface&& surface) noexcept;
	Surface& operator=(const Surface& other) = default;
	Surface& operator=(Surface&& other) noexcept;

	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
	void Fill(Color c);

	int GetWidth() const;
	int GetHeight() const;

	RectI GetRect() const;
private:
	void ReadSurfaceFile(const std::string& fileName);
private:
	std::vector<Color> pPixels;
	int width = 0;
	int height = 0;
};

