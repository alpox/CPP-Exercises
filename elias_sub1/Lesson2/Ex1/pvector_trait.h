//
// Created by Elias on 06.10.16.
//

#ifndef EX1_PVECTOR_H
#define EX1_PVECTOR_H

include <stdlib.h>

using namespace std;

template<typename T> struct persistence_traits {
    static void read(ifstream &i, T &elem) {
        i >> elem;
    }
    static void write(ofstream &o, const T &elem) {
        o << elem << endl;
    }
}

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

    void readvector() {
        ifstream ifs(filename);
        for(;;) {
            if(!ifs.good()) break;

            T readElement;
            vec.push_back(persister::read(ifs, readElement));
            vec.push_back(readElement);
        }
    }

    void writevector() {
        ofstream ofs(filename);
        typename iterator fst=vec.begin(), lst=vec.end();
        while(fst!=lst) persister::write(ofs, *fst++);
    }
}

#endif //EX1_PVECTOR_H
