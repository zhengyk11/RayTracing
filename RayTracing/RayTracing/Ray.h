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
	Vector3 O;	//���
	Vector3 N;	//��ʾ����ĵ�λ����
};

#endif
