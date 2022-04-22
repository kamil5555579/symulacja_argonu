#include<iostream>
#include <vector>
#include "wektor3d.h"
#include "atom.h"
#include "krystalografia.h"
using namespace std;

int main()
{
	vector<Atom> atomy = GenerujKrysztalFCC (1, 5.256e-10, 5, 5, 5);
	ZapiszKlatkeXYZ (cout, atomy, 0.5);
}