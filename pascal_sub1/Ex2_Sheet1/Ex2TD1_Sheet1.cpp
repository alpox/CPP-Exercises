#include <iostream>
#include "fraction.h"
#include "fracOp.h"
#include "fracPrint.h"
using namespace std;

int main(int argc, char** argv) {
	fraction a = fraction(2,1);
	fraction b = fraction(3,4);
	fraction c = fraction(-3,2);
	cout << a << " + " << b << " = " << a+b << "\n";
	cout << a << " * " << b << " = " << a*b << "\n";
	cout << a << " / " << b << " = " << a/b << "\n";
	cout << a << " - " << b << " = " << a-b << "\n";
	cout << b << " + " << c << " = " << b+c << "\n";
	cout << c << " / " << b << " = " << c/b << "\n";
	cout << b << " + " << c << " * " << a << " = " << b+c*a << "\n";
	return 0;
}