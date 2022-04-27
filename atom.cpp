#include "atom.h"
#include <vector>
#include "wektor3d.h"

Atom::Atom (double masa, double x0, double y0,  double z0, double vx0, double vy0, double vz0):
	m (masa), s (x0, y0, z0), v (vx0, vy0, vz0)
{
	// celowo on jest pusty i tak jest fajnie  
}

void ZapiszKlatkeXYZ (std::ostream &os, const std::vector<Atom> &atomy, double ts)
{
	Wektor3D tmp;
	os<<"500"<<"\n"<<ts<<"\n";
	for(int i=0; i<atomy.size(); i++)
	{
		tmp=atomy[i].s*1e10;
		os<<"Ar"<<"\t"<<tmp<<"\n";
	}
}
void ZapiszPredkosci (std::ostream &os, const std::vector<Atom> &atomy)
{
	for(int i=0; i<atomy.size(); i++)
		os<<atomy[i].v<<"\t"<< atomy[i].v.mod() <<"\n";
}