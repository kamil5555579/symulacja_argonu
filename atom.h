#ifndef _atom_h_
#define _atom_h_
#include "wektor3d.h"
#include <vector>

struct Atom
{
	Atom (double masa, double x0 = 0, double y0 = 0,  double z0 = 0, double vx0 = 0, double vy0 = 0, double vz0 = 0);
	double m;
	Wektor3D s;
	Wektor3D v;
};

void ZapiszKlatkeXYZ (std::ostream &os, const std::vector<Atom> &atomy, double ts);
void ZapiszPredkosci (std::ostream &os, const std::vector<Atom> &atomy);
#endif