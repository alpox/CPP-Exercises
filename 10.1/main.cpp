#include <iostream>
#include <vector>

template<typename I> using DifferenceTypeOf =
    typename std::iterator_traits<I>::difference_type;

template<typename I> using IteratorCategoryOf =
    typename std::iterator_traits<I>::iterator_category;

template<typename I> using IsRandomAccessIterator =
    std::is_base_of<std::random_access_iterator_tag, IteratorCategoryOf<I>>;

template<typename I> using IsInputIterator =
    std::is_base_of<std::input_iterator_tag, IteratorCategoryOf<I>>;

template<bool B, typename T = void> using EnableIf =
    typename std::enable_if<B,T>::type;

template<typename Ran> DifferenceTypeOf<EnableIf<IsRandomAccessIterator<Ran>::value>>
__distance(Ran first, Ran last, std::random_access_iterator_tag dummy){
    return last-first;
}

template<typename In> DifferenceTypeOf<EnableIf<IsInputIterator<In>::value>>
__distance(In first, In last, std::input_iterator_tag dummy){
    DifferenceTypeOf<EnableIf<IsInputIterator<In>::value>> n = 0;
    while(first != last){
        ++first;
        ++n;
    }
    return n;
}

template<typename I> DifferenceTypeOf<I> myDistance(I first, I last){
    typedef IteratorCategoryOf<I> cat;
    return __distance(first, last, cat());
}

void testDriver(){
    std::vector<int> test = {2,4,8,16,32,64,128,256,512,1024};
    std::vector<int>::iterator first = test.begin(), last = test.end();
    std::cout << "Distance of begin and end iterator on a vector with 10 entries: " << myDistance(first, last) << std::endl;
    ++first; --last;
    std::cout << "Distance of begin and end iterator after we moved each 1 closer to the other: " << myDistance(first, last) << std::endl;
}

int main() {
    testDriver();
    return 0;
}