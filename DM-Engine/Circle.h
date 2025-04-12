#ifndef CIRCLE_H
#define CIRCLE_H

template<typename T>
struct Circle
{
	T x;
	T y;
	T radius;
};

typedef Circle<int> IntCircle;
typedef Circle<float> FloatCircle;
typedef Circle<double> DoubleCircle;

#endif