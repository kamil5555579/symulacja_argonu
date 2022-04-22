#include "wektor3d.h"
#include <cmath>

Wektor3D::Wektor3D ()
{
	x = 0;
	y = 0;
	z = 0;
}
Wektor3D::Wektor3D (double x0, double y0, double z0)
{
	x = x0;
	y = y0;
	z = z0;
}
double Wektor3D::mod2 () const
{
	return x*x + y*y + z*z;
}
double Wektor3D::mod () const
{
	return sqrt(mod2());
}
Wektor3D operator+ (const Wektor3D &w1, const Wektor3D &w2)
{
	Wektor3D suma (w1.x + w2.x, w1.y +w2.y, w1.z + w2.z);
	return suma;
}
Wektor3D operator- (const Wektor3D &w1, const Wektor3D &w2)
{
	Wektor3D roznica (w1.x - w2.x, w1.y -w2.y, w1.z - w2.z);
	return roznica;
}
std::ostream &operator<< (std::ostream &os, const Wektor3D &w)
{
	os << w.x << '\t' << w.y << "\t" << w.z;
	return os;
}
Wektor3D operator* (const Wektor3D &w, double ang)
{
	Wektor3D iloczyn (w.x * ang, w.y * ang, w.z * ang);
	return iloczyn;
}