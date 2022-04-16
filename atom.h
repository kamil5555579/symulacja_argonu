#ifndef _atom_h_
#define _atom_h_
#include "wektor3d.h"

struct Obiekt2D
{
	Obiekt2D (int kolor, double masa, int promien, double x0 = 0, double y0 = 0, double vx0 = 0, double vy0 = 0);
	int k;
	double m;
	int r;
	Wektor2D s;
	Wektor2D v;
};

#endif