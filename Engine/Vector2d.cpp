//#include "Vector2d.h"
//#include <cmath>
//
//template <typename T>
//Vector2d<T>::Vector2d(T x_in, T y_in)
//	:
//	x(x_in),
//	y(y_in)
//{
//}
//
//template <typename T>
//Vector2d<T> Vector2d<T>::operator+(const Vector2d<T>& rhs) const
//{
//	return Vector2d<T>(x + rhs.x, y + rhs.y);
//}
//
//template <typename T>
//Vector2d<T>& Vector2d<T>::operator+=(const Vector2d<T>& rhs)
//{
//	return *this = *this + rhs;
//}
//
//template <typename T>
//Vector2d<T> Vector2d<T>::operator*(T rhs) const
//{
//	return Vector2d(x * rhs, y * rhs);
//}
//
//template <typename T>
//Vector2d<T>& Vector2d<T>::operator*=(T rhs)
//{
//	return *this = *this * rhs;
//}
//
//template <typename T>
//Vector2d<T> Vector2d<T>::operator-(const Vector2d<T>& rhs) const
//{
//	return Vector2d(x - rhs.x, y - rhs.y);
//}
//
//template <typename T>
//Vector2d<T>& Vector2d<T>::operator-=(const Vector2d<T>& rhs)
//{
//	return *this = *this - rhs;
//}
//
//template <typename T>
//Vector2d<T> Vector2d<T>::operator/(T rhs) const
//{
//	return Vector2d(x / rhs, y / rhs);
//}
//
//template <typename T>
//Vector2d<T>& Vector2d<T>::operator/=(T rhs)
//{
//	return *this = *this / rhs;
//}
//
//template <typename T>
//float Vector2d<T>::GetLength() const
//{
//	return std::sqrt(float(GetLengthSq()));
//}
//
//template <typename T>
//T Vector2d<T>::GetLengthSq() const
//{
//	return x * x + y * y;
//}