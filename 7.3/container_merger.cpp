
#include "container_merger.h"
#include <iterator>
#include <algorithm>

void container_merger::merge(const std::vector<int> &in1, const std::vector<int> &in2, std::vector<int> &out) {
        std::copy(in1.begin(), in1.end(), std::back_inserter(out));
        std::copy(in2.begin(), in2.end(), std::back_inserter(out));
}