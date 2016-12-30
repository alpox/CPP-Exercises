//
// Created by Elias on 11.10.16.
//

#ifndef EX1_PERSISTENCE_TRAITS_H_H
#define EX1_PERSISTENCE_TRAITS_H_H

#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
struct persistence_traits {
    static void read(ifstream &i, T &elem) {
        i >> elem;
    }
    static void write(ofstream &o, const T &elem) {
        o << elem << endl;
    }
};

#endif //EX1_PERSISTENCE_TRAITS_H_H
