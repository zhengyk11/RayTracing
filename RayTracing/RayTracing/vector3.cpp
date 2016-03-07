#include"Vector3.h"
#include<cmath>
#include<sstream>

const double EPS = 1e-6;

Vector3::Vector3() {
	x = y = z = 0;
}

Vector3::Vector3(double X, double Y, double Z) {
	x = X;
	y = Y;
	z = Z;
}

Vector3 operator + ( const Vector3& A , const Vector3& B ) {
	return Vector3( A.x + B.x , A.y + B.y , A.z + B.z );
}

Vector3 operator - ( const Vector3& A , const Vector3& B ) {
	return Vector3( A.x - B.x , A.y - B.y , A.z - B.z );
}

Vector3 operator * ( const Vector3& A , const double& k ) {
	return Vector3( A.x * k , A.y * k , A.z * k );
}

Vector3 operator / ( const Vector3& A , const double& k ) {
	return Vector3( A.x / k , A.y / k , A.z / k );
}

Vector3 operator * ( const Vector3& A , const Vector3& B ) {
	return Vector3( A.y * B.z - A.z * B.y , A.z * B.x - A.x * B.z , A.x * B.y - A.y * B.x );
}

Vector3& operator += ( Vector3& A , const Vector3& B ) {
	A = A + B;
	return A;
}

Vector3& operator -= ( Vector3& A , const Vector3& B ) {
	A = A - B;
	return A;
}

Vector3& operator *= ( Vector3& A , const double& k ) {
	A = A * k;
	return A;
}

Vector3& operator /= ( Vector3& A , const double& k ) {
	A = A / k;
	return A;
}

Vector3& operator *= ( Vector3& A , const Vector3& B ) {
	A = A * B;
	return A;
}

Vector3 operator - ( const Vector3& A ) {
	return Vector3( -A.x , -A.y , -A.z );
}

double Vector3::Dot( const Vector3& A ) {
	return x * A.x + y * A.y + z * A.z;
}

double Vector3::Module2() {
	return x * x + y * y + z * z;
}

double Vector3::Module() {
	return sqrt( x * x + y * y + z * z );
}

Vector3 Vector3::GetUnitVector() {
	return *this / Module();
}

bool Vector3::IsZeroVector() {
	return (fabs( x ) < EPS) && (fabs( y ) < EPS) && (fabs( z ) < EPS);
}

void Vector3::Input( std::stringstream& fin ) {
	fin >> x >> y >> z;
}

std::ostream& operator << (std::ostream& cout, Vector3& a)
{
	cout << a.x <<  ' ' << a.y << ' ' << a.z;
	return cout;
}
