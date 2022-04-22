#ifndef _wektor3d_h_
#define _wektor3d_h_
#include<iostream>
struct Wektor3D
{
	// Konstruktory
	Wektor3D ();
	Wektor3D (double x0, double y0, double z0);
	// Metody
	double mod2 () const;
	double mod () const;
	// Skladowe
	double x;
	double y;
	double z;
};

Wektor3D operator+ (const Wektor3D &w1, const Wektor3D &w2);
Wektor3D operator- (const Wektor3D &w1, const Wektor3D &w2);
std::ostream &operator<< (std::ostream &os, const Wektor3D &w);
Wektor3D operator* (const Wektor3D &w, double ang);
#endif