
#ifndef CPP_EXERCISES_RANGEITERATOR_H
#define CPP_EXERCISES_RANGEITERATOR_H 

#include <stdexcept>

class RangeIterator {
private:
    int * start;
    int * stop;
    int * ptr;
public:
    RangeIterator(int * start, int * stop);
    ~RangeIterator();
    RangeIterator(const RangeIterator& ri);

    RangeIterator& operator++() throw (std::range_error);
    RangeIterator operator++(int) throw (std::range_error);

    int *begin() const;

    int *end() const;

    bool operator==(const RangeIterator &ri);
    bool operator!=(const RangeIterator &ri);

    int& operator*();
};

#endif // CPP_EXERCISES_RANGEITERATOR_H
