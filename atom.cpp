#include "atom.h"
#include <vector>

Atom::Atom (double masa, double x0, double y0,  double z0, double vx0, double vy0, double vz0):
	m (masa), s (x0, y0, z0), v (vx0, vy0, vz0)
{
	// celowo on jest pusty i tak jest fajnie  
}

void ZapiszKlatkeXYZ (std::ostream &os, const std::vector<Atom> &atomy, double ts)
{
	os<<"500"<<"\n"<<ts<<"\n";
	for(int i=0; i<atomy.size(); i++)
	{
		Wektor3D tmp=atomy[i].s*1e10;
		os<<"Ar"<<"\t"<<tmp<<"\n";
	}
}