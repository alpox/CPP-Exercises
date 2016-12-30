#include <iostream>
#ifndef FRACTION_H
#define FRACTION_H
using namespace std;

class fraction{
	friend istream &operator>>(istream &is, fraction &f);
	friend ostream &operator<<(ostream &os, fraction f);
	friend bool operator<(fraction, fraction);
	private:
		int cntr; 
		int denom;
	public:
		fraction();
		fraction(int c, int d);
		int get_counter();
		void set_counter(int c);
		int get_denominator();
};

#endif
