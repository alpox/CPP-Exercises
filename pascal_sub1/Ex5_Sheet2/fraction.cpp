#include <iostream>
#include "fracOp.h"
#include "fraction.h"

fraction::fraction(){
	cntr = 0;
	denom = 1;
}

fraction::fraction(int c, int d){
	cntr = c; 
	denom = d; 
}
	
int fraction::get_counter() {
	return cntr; 
}
	
void fraction::set_counter(int c) {
	cntr=c; 
}

int fraction::get_denominator() {
	return denom; 
}
