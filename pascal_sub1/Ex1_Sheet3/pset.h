#ifndef EX1_SHEET3_PSET_H
#define EX1_SHEET3_PSET_H

#include <set>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <typename T>
class pset {
    set<T> s;
    string filename;
public:
    void readset(){
        ifstream ifs(filename);
        for(;;) {
            T x; ifs >> x;
            if(!ifs.good())
                break;
            s.insert(x);
        }
    }
    void writeset(){
        ofstream ofs(filename);
        typename set<T>::iterator fst=s.begin(), lst=s.end();
        while(fst!=lst){
            ofs << *fst++ << endl;
        }
    }
    pset(string fname) : filename(fname) {
            readset();
    }
    ~pset() {
        writeset();
    }
    void add(T a){
        s.insert(a);
    }
    void remove(T a){
        s.erase(a);
    }
    set<T> get_set(){
        return s;
    }
};


#endif //EX1_SHEET3_PSET_H
