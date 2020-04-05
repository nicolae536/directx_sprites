#include "RectI.h"

RectI::RectI(int left_in, int right_in, int top_in, int bottom_in)
	:
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)
{
}

RectI::RectI(const Vector2d<int>& topLeft, const Vector2d<int>& bottomRight)
	:
	RectI(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
{
}

RectI::RectI(const Vector2d<int>& topLeft, int width, int height)
	:
	RectI(topLeft, topLeft + Vector2d<int>(width, height))
{
}

bool RectI::IsOverlappingWith(const RectI& other) const
{
	return right > other.left && left < other.right
		&& bottom > other.top && top < other.bottom;
}

bool RectI::IsContainedBy(const RectI& other) const
{
	return left >= other.left && right <= other.right &&
		top >= other.top && bottom <= other.bottom;
}

bool RectI::Contains(const Vector2d<int>& point) const
{
	return point.x >= left && point.x < right&& point.y >= top && point.y < bottom;
}

RectI RectI::FromCenter(const Vector2d<int>& center, int halfWidth, int halfHeight)
{
	const Vector2d<int> half(halfWidth, halfHeight);
	return RectI(center - half, center + half);
}

RectI RectI::GetExpanded(int offset) const
{
	return RectI(left - offset, right + offset, top - offset, bottom + offset);
}

Vector2d<int> RectI::GetCenter() const
{
	return Vector2d<int>((left + right) / 2, (top + bottom) / 2);
}

int RectI::GetWidth() const
{
	return right - left;
}

int RectI::GetHeight() const
{
	return bottom - top;
}