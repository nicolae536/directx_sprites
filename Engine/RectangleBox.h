#pragma once

#include "Vector2d.h"

template<typename T>
class RectangleBox
{
public:
	RectangleBox() = default;

	RectangleBox(T left_in, T right_in, T top_in, T bottom_in)
		:
		left(left_in),
		right(right_in),
		top(top_in),
		bottom(bottom_in)
	{
	}

	RectangleBox(const Vector2d<T>& topLeft, const Vector2d<T>& bottomRight)
		:
		RectangleBox(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
	{
	}

	RectangleBox(const Vector2d<T>& topLeft, T width, T height)
		:
		RectangleBox(topLeft, topLeft + Vector2d<T>(width, height))
	{
	}

	bool IsOverlappingWith(const RectangleBox& other) const
	{
		return right > other.left && left < other.right
			&& bottom > other.top && top < other.bottom;
	}

	bool IsContainedBy(const RectangleBox& other) const
	{
		return left >= other.left && right <= other.right &&
			top >= other.top && bottom <= other.bottom;
	}

	bool Contains(const Vector2d<T>& point) const
	{
		return point.x >= left && point.x < right&& point.y >= top && point.y < bottom;
	}

	RectangleBox FromCenter(const Vector2d<T>& center, T halfWidth, T halfHeight)
	{
		const Vector2d<T> half(halfWidth, halfHeight);
		return RectangleBox(center - half, center + half);
	}

	RectangleBox GetExpanded(T offset) const
	{
		return RectangleBox(left - offset, right + offset, top - offset, bottom + offset);
	}

	Vector2d<T> GetCenter() const
	{
		return Vector2d<T>((left + right) / 2, (top + bottom) / 2);
	}

	T GetWidth() const
	{
		return right - left;
	}

	T GetHeight() const
	{
		return bottom - top;
	}

public:
	T left;
	T right;
	T top;
	T bottom;
};

typedef RectangleBox<int> RectI;