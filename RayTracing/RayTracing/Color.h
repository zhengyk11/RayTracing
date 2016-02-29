#ifndef COLOR_H
#define COLOR_H

#include<sstream>

class Color {
public:
	Color();
	Color( double R, double G, double B);
	~Color();

	friend Color operator + ( const Color& , const Color& );
	friend Color operator - ( const Color& , const Color& );
	friend Color operator * ( const Color& , const Color& );
	friend Color operator * ( const Color& , const double& );
	friend Color operator / ( const Color& , const double& );
	friend Color& operator += ( Color& , const Color& );
	friend Color& operator -= ( Color& , const Color& );
	friend Color& operator *= ( Color& , const double& );
	friend Color& operator /= ( Color& , const double& );
	friend std::ostream& operator << (std::ostream& cout, Color& a);
	void Confine();		//luminance must be less than or equal to 1
	void Input( std::stringstream& );

public:
	double r, g, b;
};

#endif
