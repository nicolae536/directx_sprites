
#pragma once
#include <cmath>

template <typename T>
class Vector2d
{
public:
	Vector2d() = default;
	Vector2d(T x_in, T y_in)
		:
		x(x_in),
		y(y_in)
	{
	};
	template<typename S>
	explicit Vector2d(const Vector2d<S>& src)
		:x((T)src.x),
		y((T)src.y)
	{
	}
	Vector2d operator+(const Vector2d& rhs) const
	{
		return Vector2d(x + rhs.x, y + rhs.y);
	};
	Vector2d& operator+=(const Vector2d& rhs)
	{
		return *this = *this + rhs;
	};
	Vector2d operator*(T rhs) const
	{
		return Vector2d(x * rhs, y * rhs);
	};
	Vector2d& operator*=(T rhs)
	{
		return *this = *this * rhs;
	};
	Vector2d operator-(const Vector2d& rhs) const
	{
		return Vector2d(x - rhs.x, y - rhs.y);
	};
	Vector2d& operator-=(const Vector2d& rhs)
	{
		return *this = *this - rhs;
	};
	Vector2d operator/(T rhs) const
	{
		return Vector2d(x / rhs, y / rhs);
	};
	Vector2d& operator/=(T rhs)
	{
		return *this = *this / rhs;
	};
	Vector2d& Normalize() {
		return *this = GetNormalized();
	}
	Vector2d GetNormalized() {
		const T len = GetLength();
		if (len != (T)0) {
			return *this * ((T)1 / len);
		}
		return *this;
	}
	T GetLength() const
	{
		return (T)std::sqrt(GetLengthSq());
	};
	T GetLengthSq() const
	{
		return x * x + y * y;
	};

	void SetDirection(Vector2d dir) {
		if ((dir.x > 0 && x < 0) || (dir.x < 0 && x > 0)) {
			x *= (T)-1;
		}

		if ((dir.y > 0 && y < 0) || (dir.y < 0 && y > 0)) {
			y *= (T)-1;
		}
	}
public:
	T x;
	T y;
};