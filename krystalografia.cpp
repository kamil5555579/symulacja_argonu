#include "krystalografia.h"
#include <vector>
#include <stdio.h> 
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cmath>
double k = 1.38e-23; // stala boltzmanna
double pi = 3.1416;

std::vector<Atom> GenerujKrysztalFCC (double masa, double a, unsigned m1, unsigned m2, unsigned m3, double T)
{
	srand (time(NULL));
	double theta;
	double phi;
	double vp = sqrt((8*k*T)/(pi*masa));
	std::vector <Atom> atomy;
	for(double x = 0; x<m1*a;  x+=a)
	for(double y = 0; y<m1*a;  y+=a)
	for(double z = 0; z<m1*a;  z+=a)
	{
		theta = (rand() % 31415) / 10000.0; 
		phi = (rand() % 31415) / 5000.0;
		atomy.emplace_back (masa, x, y, z, vp*sin(theta)*cos(phi), vp*sin(theta)*sin(phi), vp*cos(theta));
		theta = (rand() % 31415) / 10000.0; 
		phi = (rand() % 31415) / 5000.0;
		atomy.emplace_back (masa, x+a/2, y+a/2, z, vp*sin(theta)*cos(phi), vp*sin(theta)*sin(phi), vp*cos(theta));
		theta = (rand() % 31415) / 10000.0; 
		phi = (rand() % 31415) / 5000.0;
		atomy.emplace_back (masa, x+a/2, y, z+a/2, vp*sin(theta)*cos(phi), vp*sin(theta)*sin(phi), vp*cos(theta));
		theta = (rand() % 31415) / 10000.0; 
		phi = (rand() % 31415) / 5000.0;
		atomy.emplace_back (masa, x, y+a/2, z+a/2, vp*sin(theta)*cos(phi), vp*sin(theta)*sin(phi), vp*cos(theta));
	}
	return atomy;
}