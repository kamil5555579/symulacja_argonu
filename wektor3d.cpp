#include "wektor3d.h"
#include <cmath>

Wektor2D::Wektor2D ()
{
	x = 0;
	y = 0;
}
Wektor2D::Wektor2D (double x0, double y0)
{
	x = x0;
	y = y0;
}
double Wektor2D::mod2 () const
{
	return x*x + y*y;
}
double Wektor2D::mod () const
{
	return sqrt(mod2());
}
Wektor2D operator+ (const Wektor2D &w1, const Wektor2D &w2)
{
	Wektor2D suma (w1.x + w2.x, w1.y +w2.y);
	return suma;
}
Wektor2D operator- (const Wektor2D &w1, const Wektor2D &w2)
{
	Wektor2D roznica (w1.x - w2.x, w1.y -w2.y);
	return roznica;
}
std::ostream &operator<< (std::ostream &os, const Wektor2D &w)
{
	os << w.x << '\t' << w.y;
	return os;
}