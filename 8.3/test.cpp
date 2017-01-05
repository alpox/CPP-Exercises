
#include <cassert>
#include <iostream>
#include "playfield.h"

void test_playfield_equals(){
	playfield_impl field1;
	playfield_impl field2;

	field1.set_stone_in_column(1,0);
	field1.set_stone_in_column(2,1);
	field2.set_stone_in_column(1,0);
	field2.set_stone_in_column(2,1);

	assert(field1 == field2);
}

int main(){
	test_playfield_equals();
	std::cout << "All tests passed" << std::endl;
	return 0;
}