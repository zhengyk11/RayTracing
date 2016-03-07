#include "Light.h"

INTERSECTION_TYPE PointLight::Collide(Ray ray, double& out_dist)
{
	return MISS;
}

void PointLight::Input( std::string var, std::stringstream& fin)
{
	if (var == "O=") O.Input(fin);
	if (var == "color=") color.Input(fin);
}

INTERSECTION_TYPE PlaneLight::Collide(Ray ray, double& out_dist)
{
	Vector3 N = dx * dy;
	double ndotn = ray.N.Dot(N);
	if (fabs(ndotn) > EPS)
	{
		double t = (O - ray.O).Dot(N) / ndotn;
		if (t > EPS)
		{
			Vector3 ip = ray.GetPoint(t);
			if (fabs((ip - O).Dot(dx)) < dx.Dot(dx) 
				&& fabs((ip - O).Dot(dy)) < dy.Dot(dy))
				return INTERSECTED;
		}
	}
	return MISS;
}

void PlaneLight::Input( std::string var, std::stringstream& fin)
{
	if (var == "O=") O.Input(fin);
	if (var == "color=") color.Input(fin);
	if (var == "dx=") dx.Input(fin);
	if (var == "dy=") dy.Input(fin);
}