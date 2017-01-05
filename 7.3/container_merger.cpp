
#include "container_merger.h"
#include <iterator>
#include <algorithm>

template<typename input_container1_t,
        typename input_container2_t,
        typename output_container_t>
void container_merger<input_container1_t, input_container2_t, output_container_t>::merge(const input_container1_t &in1, const input_container2_t &in2, output_container_t &out) {
        std::copy(in1.begin(), in1.end(), std::back_inserter(out));
        std::copy(in2.begin(), in2.end(), std::back_inserter(out));
}

template class container_merger<std::vector<int> >;
template class container_merger<std::vector<double> >;
template class container_merger<std::vector<char> >;