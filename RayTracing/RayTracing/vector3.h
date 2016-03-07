#ifndef VECTOR3_H
#define VECTOR3_H

#include<sstream>

extern const double EPS;

class Vector3 {
public:
	Vector3();
	Vector3( double X, double Y, double Z);
	~Vector3() {}

	friend Vector3 operator + ( const Vector3& , const Vector3& );
	friend Vector3 operator - ( const Vector3& , const Vector3& );
	friend Vector3 operator * ( const Vector3& , const double& );
	friend Vector3 operator / ( const Vector3& , const double& );
	friend Vector3 operator * ( const Vector3& , const Vector3& ); //cross product
	friend Vector3& operator += ( Vector3& , const Vector3& );
	friend Vector3& operator -= ( Vector3& , const Vector3& );
	friend Vector3& operator *= ( Vector3& , const double& );
	friend Vector3& operator /= ( Vector3& , const double& );
	friend Vector3& operator *= ( Vector3& , const Vector3& );
	friend Vector3 operator - ( const Vector3& );
	friend std::ostream& operator << (std::ostream& cout, Vector3& a);

	double Dot( const Vector3& ); //dot product
	double Module2();
	double Module();
	Vector3 GetUnitVector();
	bool IsZeroVector();
	void Input( std::stringstream& fin );

public:
	double x , y , z;
};

#endif
