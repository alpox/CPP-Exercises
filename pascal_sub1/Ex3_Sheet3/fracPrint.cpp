#include "fracPrint.h"
#include "fraction.h"
#include "fracOp.h"
using namespace std;

inline void check_char(istream &is, char ch) {
	char c; 
	is >> c; 
	if(c!=ch) { 
		is.putback(c); 
		is.setstate(std::ios_base::badbit); 
	}
}

istream &operator>>(istream &is, fraction &f) {
	fraction g = fraction(0,1);
	check_char(is,'(');
	is >> g.cntr;
	check_char(is,'/'); 
	is >> g.denom;
	check_char(is,')'); 
	if(is) f=g;
	return is;
}

ostream &operator<<(ostream &os, fraction f) {
	os << '(' << f.cntr << '/' << f.denom << ')';
	return os;
}

void printEquation(char c, fraction a, fraction b){
	if(c == '+'){
		cout << a << " + " << b << " = " << a+b;
	}else if(c == '-'){
		cout << a << " - " << b << " = " << a-b;
	}else if(c == '*'){
		cout << a << " * " << b << " = " << a*b;
	}else if(c == '/'){
		cout << a << " / " << b << " = " << a/b;
	}else{
		cout << "Your input was wrong. Please restart the program.";
	}
}
