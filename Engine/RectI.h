#pragma once

#include "Vector2d.h"

class RectI
{
public:
	RectI() = default;
	RectI(int left_in, int right_in, int top_in, int bottom_in);
	RectI(const Vector2d<int>& topLeft, const Vector2d<int>& bottomRight);
	RectI(const Vector2d<int>& topLeft, int width, int height);
	bool IsOverlappingWith(const RectI& other) const;
	bool IsContainedBy(const RectI& other) const;
	bool Contains(const Vector2d<int>& point) const;
	static RectI FromCenter(const Vector2d<int>& center, int halfWidth, int halfHeight);
	RectI GetExpanded(int offset) const;
	Vector2d<int> GetCenter() const;
	int GetWidth() const;
	int GetHeight() const;
public:
	int left;
	int right;
	int top;
	int bottom;
};