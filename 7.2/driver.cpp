
#include "stack.h"
#include <iostream>

int main(){

	static_stack s;
	s.push('h');
	std::cout << s.pop() << std::endl;

	unlimited_stack u_s;
	u_s.push('h');
	std::cout << u_s.pop() << std::endl;

	return 0;
}