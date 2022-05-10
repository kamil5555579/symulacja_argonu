#include<iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "wektor3d.h"
#include "atom.h"
#include "krystalografia.h"
using namespace std;

const double m = 6.6e-23;  // masa atomu argonu
const double k = 1.38e-23; //boltzmann
const double epsilon = k*125.7, sigma = 0.3345e-9; // z modelu white'a

Wektor3D SilaLJ (const Atom &o1, const Atom &o2)
{
	Wektor3D F;
	Wektor3D r = o2.s - o1.s;
	double r1 = r.mod ();
	double F1 = 4 * epsilon * (6*pow(sigma,6)/pow(r1,7) - 12*pow(sigma,12)/pow(r1,13));
	F.x = F1 * (1/ r1) * (-r.x);
	F.y = F1 * (1/ r1) * (-r.y);
	F.z = F1 * (1/ r1) * (-r.z);
	
	return F;
}


int main()
{
	vector<Atom> atomy = GenerujKrysztalFCC (m, 5.256e-10, 5, 5, 5, 40);
	double dt=1e-12;
	for (double t=0; t<1e-10; t+=dt)
	{
		vector <Wektor3D> Fw (atomy.size());
		for (unsigned a1=1; a1<atomy.size(); a1++)
		{
			
			for(unsigned a2=0; a2<a1; a2++)
			{
				Wektor3D F = SilaLJ (atomy[a1], atomy[a2]);
				Fw[a1] = Fw[a1] - F;
				Fw[a2] = Fw[a2] + F;
			}
		
			for(unsigned a1 =0; a1<atomy.size(); a1++)
			{

				atomy[a1].s.x += atomy[a1].v.x *dt;
				atomy[a1].v.x += Fw[a1].x / atomy[a1].m * dt;
				atomy[a1].s.y += atomy[a1].v.y *dt;
				atomy[a1].v.y += Fw[a1].y / atomy[a1].m *dt;
				atomy[a1].s.z += atomy[a1].v.z*dt;
				atomy[a1].v.z += Fw[a1].z / atomy[a1].m * dt;
			}
		}				
		ZapiszKlatkeXYZ (cout, atomy, t*1000000000000);
	}
	

	ofstream plik ("predkosci.txt");
	ZapiszPredkosci (plik, atomy);
	plik.close();
}





/*

for(int i=0; i<=3000000; i++)
	{
		/*if (i % 50 == 0)
		{
			printf("%lf\t" , t);
			for(unsigned p1=1; p1<planety.size(); p1++)
				cout << planety[p1].s << '\t';
			printf("\n");
		} 
		
		
		if (i % 100 ==0)
		{
				rysuj(planety);
				rest(5);
		}
		vector <Wektor2D> Fw (planety.size());
		for(unsigned p1=1; p1<planety.size(); p1++)
		{
		
			for(unsigned p2=0; p2<p1; p2++)
				{
					Wektor2D F = SilaGrawitacji(planety[p1],planety[p2]);
					Fw[p1] = Fw[p1] - F;
					Fw[p2] = Fw[p2] + F;
				}
			for(unsigned p1=0; p1<planety.size(); p1++)
			{
				planety[p1].v.x += Fw[p1].x / planety[p1].m * dt;
				planety[p1].v.y += Fw[p1].y / planety[p1].m * dt;
				planety[p1].s.x += planety[p1].v.x * dt;
				planety[p1].s.y += planety[p1].v.y * dt;
			}
			t += dt;
		}
	}
}


*/