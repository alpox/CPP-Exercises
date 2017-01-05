
#ifndef CONTAINERMERGER_H
#define CONTAINERMERGER_H

#include <vector>

template<typename input_container1_t,
        typename input_container2_t = input_container1_t,
        typename output_container_t = input_container1_t>
class container_merger {
public:
    static void merge(const input_container1_t &input_container1, const input_container2_t &input_container2, output_container_t &output_container);
};

#endif