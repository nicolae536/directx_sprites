
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
	Vector2d<T> operator+(const Vector2d<T>& rhs) const 
	{
		return Vector2d<T>(x + rhs.x, y + rhs.y);
	};
	Vector2d<T>& operator+=(const Vector2d<T>& rhs)
	{
		return *this = *this + rhs;
	};
	Vector2d<T> operator*(T rhs) const
	{
		return Vector2d(x * rhs, y * rhs);
	};
	Vector2d<T>& operator*=(T rhs)
	{
		return *this = *this * rhs;
	};
	Vector2d<T> operator-(const Vector2d<T>& rhs) const
	{
		return Vector2d(x - rhs.x, y - rhs.y);
	};
	Vector2d<T>& operator-=(const Vector2d<T>& rhs)
	{
		return *this = *this - rhs;
	};
	Vector2d<T> operator/(T rhs) const
	{
		return Vector2d(x / rhs, y / rhs);
	};
	Vector2d<T>& operator/=(T rhs)
	{
		return *this = *this / rhs;
	};
	float GetLength() const
	{
		return std::sqrt(float(GetLengthSq()));
	};
	T GetLengthSq() const
	{
		return x * x + y * y;
	};

	void SetDirection(Vector2d<T> dir) {
		if ((dir.x > 0 && x < 0) || (dir.x < 0 && x > 0)) {
			x *= (T)-1;
		}

		if ((dir.y > 0 && y < 0) || (dir.y < 0 && y > 0)) {
			y *= (T)-1;
		}
	}

	explicit operator Vector2d<int>() {
		return Vector2d<int>((int)x, (int)y);
	}

	explicit operator Vector2d<float>() {
		return Vector2d<float>((float)x, (float)y);
	}
public:
	T x;
	T y;
};