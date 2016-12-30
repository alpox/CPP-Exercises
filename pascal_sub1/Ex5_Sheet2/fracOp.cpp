#include "fracOp.h"
#include <cmath>

fraction operator*(fraction a, fraction b){
	int f1 = gcd(a.get_counter(), b.get_denominator()), f2 = gcd(b.get_counter(), a.get_denominator());
	return fraction((a.get_counter()/f1) * (b.get_counter()/f2),(a.get_denominator()/f2) * (b.get_denominator()/f1));
}

fraction operator/(fraction a, fraction b) {
	return a*fraction(b.get_denominator(), b.get_counter());
}

fraction operator+(fraction a, fraction b){
	fraction temp = fraction(a.get_counter()*b.get_denominator()+b.get_counter()*a.get_denominator(),a.get_denominator()*b.get_denominator());
	int factor = gcd(temp.get_counter(),temp.get_denominator());
	return fraction(temp.get_counter()/factor,temp.get_denominator()/factor);
}

fraction operator-(fraction a, fraction b){
	return a+fraction(-b.get_counter(),b.get_denominator());
}

bool operator<(fraction a, fraction b){
	return (a.get_counter()*b.get_denominator())<(a.get_denominator()*b.get_counter());
}
