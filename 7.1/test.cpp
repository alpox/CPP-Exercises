
#include "rangeiterator.h"

#include <stdexcept>
#include <iostream>

void testThrowsOnRangeLimit() {
    int range[] = { 1, 2, 3, 4, 5 };

    RangeIterator it(std::begin(range), std::end(range));
    while(true) {
        try {
            it++;
        }
        catch(std::range_error &e) {
            break;
        }
    }
}

int main() {
    std::cout << "All tests passed." << std::endl;
    return 0;
}
