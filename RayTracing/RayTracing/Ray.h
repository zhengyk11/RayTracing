#ifndef RAY_H
#define RAY_H

#include "Vector3.h"

class Ray
{
public:
	Ray(Vector3 to, Vector3 tn);
	~Ray() {}

	Vector3 GetPoint(double t);

public:
	Vector3 O;	//起点
	Vector3 N;	//表示方向的单位向量
};

#endif
