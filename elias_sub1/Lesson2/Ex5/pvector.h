//
// Created by Elias on 06.10.16.
//

#ifndef EX1_PVECTOR_H
#define EX1_PVECTOR_H

#include <stdlib.h>
#include <vector>
#include <fstream>

using namespace std;

template<typename T> class pvector {
    string filename;
    vector <T> vec;
public:
    pvector(string fname) : filename(fname) { readvector(); }

    ~pvector() { writevector(); }

    void push_back(const T &el) { vec.push_back(el); }

    void pop_back() { vec.pop_back(); }

    T operator[](const int idx) const {
        return vec.at(idx);
    }

    int size() const {
        return vec.size();
    }

    bool empty() const {
        return vec.empty();
    }

    T &back() {
        return vec.back();
    }

    const T & back() const {
        return vec.back();
    }

    friend ostream &operator<<(ostream &os, const pvector &p) {
        for(int t; t < p.size(); t++)
            os << p[t] << endl;
        return os;
    }

    void readvector() {
        ifstream ifs(filename);
        T readElement;
        while(ifs >> readElement) vec.push_back(readElement);
        ifs.close();
    }

    void writevector() {
        ofstream ofs(filename);
        typename vector<T>::iterator fst=vec.begin(), lst=vec.end();
        while(fst!=lst) ofs << *fst++ << endl;
        ofs.close();
    }
};

#endif //EX1_PVECTOR_H
