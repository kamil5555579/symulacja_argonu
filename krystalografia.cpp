#include "krystalografia.h"
#include <vector>

std::vector<Atom> GenerujKrysztalFCC (double masa, double a, unsigned m1, unsigned m2, unsigned m3, double T)
{
	std::vector <Atom> atomy;
	for(double x = 0; x<m1*a;  x+=a)
	for(double y = 0; y<m1*a;  y+=a)
	for(double z = 0; z<m1*a;  z+=a)
	{
		atomy.emplace_back (masa, x, y, z);
		atomy.emplace_back (masa, x+a/2, y+a/2, z);
		atomy.emplace_back (masa, x+a/2, y, z+a/2);
		atomy.emplace_back (masa, x, y+a/2, z+a/2);
	}
	return atomy;
}