#ifndef FRACOP_H
#define FRACOP_H
#include "fraction.h"
#include <cmath>
using namespace std;

	
template <class T>
T gcd(T a, T b) {
	a = abs(a);
	b = abs(b);
	if (a<b) 
		swap(a, b);
	while (b!=0) { 
		a=a-b; 
		if (a<b) 
			swap(a, b); 
	}
	return a;
}

template <class T>
inline T lcm(T a, T b){
	return (a/gcd(a,b))*b;
}

bool operator<(fraction a, fraction b);
fraction operator*(fraction a, fraction b);
fraction operator/(fraction a, fraction b);
fraction operator+(fraction a, fraction b);
fraction operator-(fraction a, fraction b);

#endif
