#include "Ray.h"


Ray::Ray(Vector3 to, Vector3 tn)
{
	O = to;
	N = tn.GetUnitVector();
}

Vector3 Ray::GetPoint(double t)
{
	return O + N * t;
}

