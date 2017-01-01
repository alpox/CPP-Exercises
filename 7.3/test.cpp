
#include <iostream>
#include "container_merger.h"
#include <cassert>

void test_merge(){
	std::vector<int> v1, v2, o;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);

    container_merger::merge(v1, v2, o);

	assert(o[0] == 1);
	assert(o[1] == 2);
	assert(o[2] == 3);
	assert(o[3] == 4);
	assert(o[4] == 5);
	assert(o[5] == 6);
}

int main(){
	test_merge();
	std::cout << "All tests passed" << std::endl;
	return 0;
}