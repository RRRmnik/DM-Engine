#ifndef RECT_H
#define RECT_H

template<typename T>
struct Rect
{
	T x;
	T y;
	T width;
	T height;
};

typedef Rect<int> IntRect;
typedef Rect<float> FloatRect;
typedef Rect<double> DoubleRect;

#endif