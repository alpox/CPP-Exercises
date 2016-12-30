//
// Created by Elias on 11.10.16.
//

#ifndef EX1_PSET_H
#define EX1_PSET_H

#include "persistence_traits.h"
#include <stdlib.h>
#include <string>
#include <set>
#include <iostream>
#include <fstream>

using namespace std;

template<typename T, typename P=persistence_traits<T>> class pset {
    string filename;
    set <T> iset;
public:
    typedef P persister;
    typedef typename set<T>::iterator iterator;

    pset(string fname) : filename(fname) { readset(); }

    ~pset() { writeset(); }

    void insert(const T &item) {
        iset.insert(item);
    }

    bool empty() {
        return iset.empty();
    }

    T &last_element() {
        return *iset.end();
    }

    void print() {
        int i = 1;
        for(iterator iter = iset.begin(); iter != iset.end(); iter++, i++)
            cout << i << ": " << *iter << endl;
    }

    void readset() {
        ifstream ifs(filename);
        for(;;) {
            T readElement;
            persister::read(ifs, readElement);
            if(!ifs.good()) break;
            iset.insert(readElement);
        }
    }

    void writeset() {
        ofstream ofs(filename, ofstream::out | ofstream::trunc);
        iterator fst=iset.begin(), lst=iset.end();
        while(fst!=lst) persister::write(ofs, *fst++);
    }
};

#endif //EX1_PSET_H
