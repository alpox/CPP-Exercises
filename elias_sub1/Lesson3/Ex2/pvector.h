//
// Created by Elias on 06.10.16.
//

#ifndef EX2_PVECTOR_H
#define EX2_PVECTOR_H

#include "persistence_traits.h"
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

template<typename T, typename P=persistence_traits<T>> class pvector {
    string filename;
    vector <T> vec;
public:
    typedef P persister;
    typedef typename vector<T>::iterator iterator;

    pvector(string fname) : filename(fname) { readvector(); }

    ~pvector() { writevector(); }

    void push_back(const T &el) { vec.push_back(el); }

    void pop_back() { vec.pop_back(); }

    bool empty() {
        return vec.empty();
    }

    void print() {
        for(int i = 0; i < vec.size(); i++)
            cout << (i+1) << ": " << vec.at(i) << endl;
    }

    void clear() {
        vec.clear();
    }

    iterator begin() {
        return vec.begin();
    }

    iterator end() {
        return vec.end();
    }

    void readvector() {
        ifstream ifs(filename);
        for(;;) {
            T readElement;
            persister::read(ifs, readElement);
            if(!ifs.good()) break;
            vec.push_back(readElement);
        }
    }

    void writevector() {
        ofstream ofs(filename, ofstream::out | ofstream::trunc);
        iterator fst=vec.begin(), lst=vec.end();
        while(fst!=lst) persister::write(ofs, *fst++);
    }
};

#endif //EX1_PVECTOR_H
