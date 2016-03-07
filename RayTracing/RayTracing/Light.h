#ifndef LIGHT_H
#define LIGHT_H

#include "Vector3.h"
#include "Color.h"
#include "Ray.h"
#include "Common.h"


class Light
{
public:
	Light() {
		color = Color();
		next = NULL;
	}
	~Light() {}

	Color GetColor() { return color; }
	Light* GetNext() { return next; }
	void SetNext(Light* n) { next = n; }

	virtual void Input(std::string var, std::stringstream& fin) = 0;
	virtual INTERSECTION_TYPE Collide(Ray ray, double& out_dist) = 0;
	virtual bool IsPoint() = 0;

protected:
	Color color;
	Light * next;
};

class PointLight : public Light
{
	
public:
	PointLight() : Light() {}
	~PointLight() {}
	Vector3 GetO() { return O; }
	
	void Input( std::string , std::stringstream& );
	INTERSECTION_TYPE Collide(Ray ray, double& out_dist);
	bool IsPoint() { return true; }

protected:
	Vector3 O;
};

class PlaneLight : public Light
{

public:
	PlaneLight() : Light() {}
	~PlaneLight() {}
	Vector3 GetO() { return O; }
	Vector3 GetDx() { return dx; }
	Vector3 GetDy() { return dy; }

	void Input( std::string , std::stringstream& );
	INTERSECTION_TYPE Collide(Ray ray, double& out_dist);
	bool IsPoint() { return false; }
	

protected:
	Vector3 O;
	Vector3 dx, dy;
};

#endif