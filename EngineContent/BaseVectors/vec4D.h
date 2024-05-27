#pragma once

#include <cmath>

template <typename T>
class Vector4D
{
public:
	T X;
	T Y;
	T Z;
	T W;

	Vector4D();
	Vector4D(T i);
	Vector4D(T A, T B, T C, T D);

	bool IsZero();
	T GetMagnitude();
	T Distance(Vector4D<T> A, Vector4D<T> B);
	Vector4D<T> GetNormalizeVector();

	Vector4D<T> operator + (Vector4D<T> B);
	Vector4D<T> operator - (Vector4D<T> B);
	Vector4D<T> operator * (Vector4D<T> B);
	Vector4D<T> operator / (Vector4D<T> B);
};


template<typename T>
inline Vector4D<T>::Vector4D()
{
	X = (T)NULL;
	Y = (T)NULL;
	Z = (T)NULL;
	W = (T)NULL;
}

template<typename T>
inline Vector4D<T>::Vector4D(T i)
{
	X = i;
	Y = i;
	Z = i;
	W = i;
}

template<typename T>
inline Vector4D<T>::Vector4D(T A, T B, T C, T D)
{
	X = A;
	Y = B;
	Z = C;
	W = D;
}

template<typename T>
inline bool Vector4D<T>::IsZero()
{
	return (X == 0 && Y == 0 && Z == 0 && W == 0);
}

template<typename T>
inline T Vector4D<T>::GetMagnitude()
{
	return sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2) + pow(W, 2));
}

template<typename T>
inline T Vector4D<T>::Distance(Vector4D<T> A, Vector4D<T> B)
{
	return sqrt(pow(A.X - B.X, 2) + pow(A.Y - B.Y, 2) + pow(A.Z - B.Z, 2), +pow(A.W - B.W, 2));
}

template<typename T>
Vector4D<T> Vector4D<T>::GetNormalizeVector()
{
	float Total = abs((float)this->X) + abs((float)this->Y) + abs((float)this->Z) + abs((float)this->W);

	Vector4D NewVec = Vector4D();

	if (Total > 0)
	{
		NewVec.X = this->X / Total;
		NewVec.Y = this->Y / Total;
		NewVec.Z = this->Z / Total;
		NewVec.W = this->W / Total;
	}

	return NewVec;
}


template<typename T>
Vector4D<T> Vector4D<T>::operator + (Vector4D<T> B)
{
	Vector4D<T> A;
	A.X = X + B.X;
	A.Y = Y + B.Y;
	A.Z = Z + B.Z;
	A.W = W + B.W;
	return A;
}

template<typename T>
Vector4D<T> Vector4D<T>::operator - (Vector4D<T> B)
{
	Vector4D<T> A;
	A.X = X - B.X;
	A.Y = Y - B.Y;
	A.Z = Z - B.Z;
	A.W = W - B.W;
	return A;
}

template<typename T>
Vector4D<T> Vector4D<T>::operator * (Vector4D<T> B)
{
	Vector4D<T> A;
	A.X = X * B.X;
	A.Y = Y * B.Y;
	A.Z = Z * B.Z;
	A.W = W * B.W;
	return A;
}

template<typename T>
Vector4D<T> Vector4D<T>::operator / (Vector4D<T> B)
{
	Vector4D<T> A;
	A.X = X / B.X;
	A.Y = Y / B.Y;
	A.Z = Z / B.Z;
	A.W = W / B.W;
	return A;
}

