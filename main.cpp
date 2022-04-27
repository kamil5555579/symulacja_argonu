#include<iostream>
#include <fstream>
#include <vector>
#include "wektor3d.h"
#include "atom.h"
#include "krystalografia.h"
using namespace std;

double m = 6.6e-23;  // masa atomu argonu

int main()
{
	vector<Atom> atomy = GenerujKrysztalFCC (m, 5.256e-10, 5, 5, 5, 40);
	ZapiszKlatkeXYZ (cout, atomy, 0.5);
	ofstream plik ("predkosci.txt");
	ZapiszPredkosci (plik, atomy);
	plik.close();
}