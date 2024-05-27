#pragma once

#include <cmath>

template <typename T>
class Vector3D
{
public:
	T X;
	T Y;
	T Z;

	Vector3D();
	Vector3D(T i);
	Vector3D(T A, T B, T C);

	bool IsZero();
	T GetMagnitude();
	T Distance(Vector3D<T> A, Vector3D<T> B);
	Vector3D<T> GetNormalizeVector();
	Vector3D<T> Cross(Vector3D<T> A, Vector3D<T> B);

	Vector3D<T> operator + (Vector3D<T> B);
	Vector3D<T> operator - (Vector3D<T> B);
	Vector3D<T> operator * (Vector3D<T> B);
	Vector3D<T> operator / (Vector3D<T> B);
};


template<typename T>
inline Vector3D<T>::Vector3D()
{
	X = (T)NULL;
	Y = (T)NULL;
	Z = (T)NULL;
}

template<typename T>
inline Vector3D<T>::Vector3D(T i)
{
	X = i;
	Y = i;
	Z = i;
}

template<typename T>
inline Vector3D<T>::Vector3D(T A, T B, T C)
{
	X = A;
	Y = B;
	Z = C;
}

template<typename T>
inline bool Vector3D<T>::IsZero()
{
	return (X == 0 && Y == 0 && Z == 0);
}

template<typename T>
inline T Vector3D<T>::GetMagnitude()
{
	return sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2));
}

template<typename T>
inline T Vector3D<T>::Distance(Vector3D<T> A, Vector3D<T> B)
{
	return sqrt(pow(A.X - B.X, 2) + pow(A.Y - B.Y, 2) + pow(A.Z - B.Z, 2));
}

template<typename T>
Vector3D<T> Vector3D<T>::GetNormalizeVector()
{
	float Total = abs((float)this->X) + abs((float)this->Y) + abs((float)this->Z);

	Vector3D NewVec = Vector3D();

	if (Total > 0)
	{
		NewVec.X = this->X / Total;
		NewVec.Y = this->Y / Total;
		NewVec.Z = this->Z / Total;
	}

	return NewVec;
}

template<typename T>
Vector3D<T> Vector3D<T>::Cross(Vector3D<T> A, Vector3D<T> B)
{
	Vector3D<T> Result;
	Result.X = (A.Y * B.Z) - (A.Z * B.Y);
	Result.Y = (A.Z * B.X) - (A.X * B.Z);
	Result.Z = (A.X * B.Y) - (A.Y * B.X);
	return Result;
}


template<typename T>
Vector3D<T> Vector3D<T>::operator + (Vector3D<T> B)
{
	Vector3D<T> A;
	A.X = X + B.X;
	A.Y = Y + B.Y;
	A.Z = Z + B.Z;
	return A;
}

template<typename T>
Vector3D<T> Vector3D<T>::operator - (Vector3D<T> B)
{
	Vector3D<T> A;
	A.X = X - B.X;
	A.Y = Y - B.Y;
	A.Z = Z - B.Z;
	return A;
}

template<typename T>
Vector3D<T> Vector3D<T>::operator * (Vector3D<T> B)
{
	Vector3D<T> A;
	A.X = X * B.X;
	A.Y = Y * B.Y;
	A.Z = Z * B.Z;
	return A;
}

template<typename T>
Vector3D<T> Vector3D<T>::operator / (Vector3D<T> B)
{
	Vector3D<T> A;
	A.X = X / B.X;
	A.Y = Y / B.Y;
	A.Z = Z / B.Z;
	return A;
}
