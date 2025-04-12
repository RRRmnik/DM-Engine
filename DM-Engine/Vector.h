#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
struct Vector2
{
	T x = 0;
	T y = 0;
};

template<typename T>
struct Vector3
{
	T x = 0;
	T y = 0;
	T z = 0;
};

template<typename T>
struct Vector4
{
	T x = 0;
	T y = 0;
	T z = 0;
	T w = 0;
};

typedef Vector2<int> Vector2i;
typedef Vector2<unsigned int> Vector2u;
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;

typedef Vector3<int> Vector3i;
typedef Vector3<unsigned int> Vector3u;
typedef Vector3<float> Vector3f;
typedef Vector3<double> Vector3d;

typedef Vector4<int> Vector4i;
typedef Vector4<unsigned int> Vector4u;
typedef Vector4<float> Vector4f;
typedef Vector4<double> Vector4d;

#endif