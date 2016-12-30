#ifndef FRACPRINT_H
#define FRACPRINT_H
#include "fraction.h"
using namespace std;

inline void check_char(istream &is, char ch);
istream &operator>>(istream &is, fraction &f);
ostream &operator<<(ostream &os, fraction f);
void printEquation(char c, fraction a, fraction b);

#endif
