//
// Created by Elias on 11.10.16.
//

#ifndef EX2_PERSISTENCE_TRAITS_H
#define EX2_PERSISTENCE_TRAITS_H

#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
struct persistence_traits {
    static void read(ifstream &i, T &elem) {
        i >> elem;
        elem.erase(remove(elem.begin(), elem.end(), '.'));
    }
    static void write(ofstream &o, const T &elem) {
        o << elem << endl;
    }
};

/*
template<>
struct persistence_traits<string> {
    static void read(ifstream &i, string &elem) {
        while(getline(i, elem));
    }
    static void write(ofstream &o, const string &elem) {
        o << elem << endl;
    }
};
*/

#endif //EX1_PERSISTENCE_TRAITS_H
