#pragma once

#include <cmath>

template <typename T>
class Vector2D
{
public:
	T X;
	T Y;

	Vector2D();
	Vector2D(T i);
	Vector2D(T A, T B);

	bool IsZero();
	T GetMagnitude();
	T Distance(Vector2D<T> A, Vector2D<T> B);
	Vector2D<T> GetNormalizeVector();

	Vector2D<T> operator + (Vector2D<T> B);
	Vector2D<T> operator - (Vector2D<T> B);
	Vector2D<T> operator * (Vector2D<T> B);
	Vector2D<T> operator / (Vector2D<T> B);
};


template<typename T>
inline Vector2D<T>::Vector2D()
{
	X = (T)NULL;
	Y = (T)NULL;
}

template<typename T>
inline Vector2D<T>::Vector2D(T i)
{
	X = i;
	Y = i;
}

template<typename T>
inline Vector2D<T>::Vector2D(T A, T B)
{
	X = A;
	Y = B;
}


template<typename T>
inline bool Vector2D<T>::IsZero()
{
	return (X == 0 && Y == 0);
}

template<typename T>
inline T Vector2D<T>::GetMagnitude()
{
	return sqrt(pow(X, 2) + pow(Y, 2));
}

template<typename T>
inline T Vector2D<T>::Distance(Vector2D<T> A, Vector2D<T> B)
{
	return sqrt(pow(A.X - B.X, 2) + pow(A.Y - B.Y, 2));
}

template<typename T>
Vector2D<T> Vector2D<T>::GetNormalizeVector()
{
	float Total = abs((float)this->X) + abs((float)this->Y);

	Vector2D NewVec = Vector2D();

	if (Total > 0)
	{
		NewVec.X = this->X / Total;
		NewVec.Y = this->Y / Total;
	}

	return NewVec;
}


template<typename T>
Vector2D<T> Vector2D<T>::operator + (Vector2D<T> B)
{
	Vector2D<T> A;
	A.X = X + B.X;
	A.Y = Y + B.Y;
	return A;
}

template<typename T>
Vector2D<T> Vector2D<T>::operator - (Vector2D<T> B)
{
	Vector2D<T> A;
	A.X = X - B.X;
	A.Y = Y - B.Y;
	return A;
}

template<typename T>
Vector2D<T> Vector2D<T>::operator * (Vector2D<T> B)
{
	Vector2D<T> A;
	A.X = X * B.X;
	A.Y = Y * B.Y;
	return A;
}

template<typename T>
Vector2D<T> Vector2D<T>::operator / (Vector2D<T> B)
{
	Vector2D<T> A;
	A.X = X / B.X;
	A.Y = Y / B.Y;
	return A;
}
