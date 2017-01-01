
#include <vector>
#include <iostream>
#include "container_merger.h"

int main() {

    std::vector<int> v1, v2, o;

    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(1);

    v2.push_back(6);
    v2.push_back(5);
    v2.push_back(4);

    container_merger::merge(v1, v2, o);

    std::cout << o[0] << std::endl << o[1] << std::endl << o[2] << std::endl << o[3] << std::endl << o[4] << std::endl << o[5] << std::endl;
    return 0;
}