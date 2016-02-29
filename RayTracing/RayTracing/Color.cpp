#include"color.h"

Color::Color(){
	r=0;
	g=0;
	b=0;
}
Color::Color(double R, double G, double B){
	r = R;
	g = G;
	b = B;
}
Color::~Color(){}
Color operator + (const Color& c1, const Color& c2){
	return Color(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
}
Color operator - (const Color& c1, const Color& c2){
	return Color(c1.r - c2.r, c1.g - c2.g, c1.b - c2.b);
}
Color operator * (const Color& c1, const Color& c2){
	return Color(c1.r * c2.r, c1.g * c2.g, c1.b * c2.b);
}
Color operator * (const Color& c, const double& k){
	return Color(c.r * k, c.g * k, c.b * k);
}
Color operator / (const Color& c, const double& k){
	return Color(c.r / k, c.g / k, c.b / k);
}
Color& operator += (Color& c1, const Color& c2){
	return c1 = c1 + c2;
}
Color& operator -= (Color& c1, const Color& c2){
	return c1 = c1 - c2;
}
Color& operator *= (Color& c, const double& k){
	return c = c * k;
}
Color& operator /= (Color& c, const double& k){
	return c = c / k;
}
std::ostream& operator << (std::ostream& cout, Color& c){
	cout << c.r << ' ' << c.g << ' ' << c.b;
	return cout;
}
void Color::Confine(){		//luminance must be less than or equal to 1
	if ( r > 1 ) r = 1;
	if ( g > 1 ) g = 1;
	if ( b > 1 ) b = 1;
}
void Color::Input(std::stringstream& fin){
	fin >> r >> g >> b;
}