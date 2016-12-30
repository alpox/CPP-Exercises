#include <iostream>

#include "pvector.h"
#include "pset.h"

int main() {
pvector<int> vec("test.txt");
if(vec.empty()) {
    vec.push_back(15);
    vec.push_back(612);
}

cout << "Vector:" << endl;

pset<int> s("set.txt");
if(s.empty()) {
    s.insert(27);
    s.insert(51);
}

vec.print();

cout << endl << "Set:" << endl;

s.print();
return 0;
}