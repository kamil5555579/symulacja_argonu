#ifndef _wektor3d_h_
#define _wektor3d_h_
#include<iostream>
struct Wektor2D
{
	// Konstruktory
	Wektor2D ();
	Wektor2D (double x0, double y0);
	// Metody
	double mod2 () const;
	double mod () const;
	// Skladowe
	double x;
	double y;
};

Wektor2D operator+ (const Wektor2D &w1, const Wektor2D &w2);
Wektor2D operator- (const Wektor2D &w1, const Wektor2D &w2);
std::ostream &operator<< (std::ostream &os, const Wektor2D &w);

#endif