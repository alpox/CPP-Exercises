
#include "rangeiterator.h"

#include <stdlib.h>
#include <stdexcept>

RangeIterator::RangeIterator(int * start, int * stop) : start(start), stop(stop), ptr(start) {}
RangeIterator::RangeIterator(const RangeIterator &ri) : start(ri.start), stop(ri.stop), ptr(ri.ptr) {}
RangeIterator::~RangeIterator() {}

RangeIterator& RangeIterator::operator++() throw (std::range_error) { 
    if(ptr+1 == stop)
        throw std::out_of_range("Tried to surpass end of the iterator range.");
    ptr++; 
    return *this; 
}

RangeIterator RangeIterator::operator++(int) throw (std::range_error) { 
    if(ptr+1 == stop)
        throw std::out_of_range("Tried to surpass end of the iterator range.");

    RangeIterator tmp(*this); 
    operator++(); 
    return tmp; 
}

int *RangeIterator::begin() const {
    return start;
}

int *RangeIterator::end() const {
    return stop;
}

bool RangeIterator::operator==(const RangeIterator &ri) {
    return start == ri.start && stop == ri.stop && ptr == ri.ptr;
}

bool RangeIterator::operator!=(const RangeIterator &ri) {
    return start != ri.start || stop != ri.stop || ptr != ri.ptr;
}

int& RangeIterator::operator*() { return *ptr; }
