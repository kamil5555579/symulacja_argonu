#ifndef _krystalografia_h_
#define _krystalografia_h_
#include "atom.h"
#include <vector>

std::vector<Atom> GenerujKrysztalFCC (double masa, double a, unsigned m1, unsigned m2, unsigned m3, double T = 0);

#endif