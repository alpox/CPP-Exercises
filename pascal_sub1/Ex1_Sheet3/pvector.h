#ifndef EX1_SHEET3_PVECTOR_H
#define EX1_SHEET3_PVECTOR_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

template<typename T>
struct persistence_traits {
    static void write(ofstream &o, const T &elem) {
        o << elem << endl;
    }
    /*static void read(ifstream &i, T &elem){

    }*/
};

template<>
struct persistence_traits<string> {
    static void write(ofstream &o, const string &elem) {
        o << elem << endl;
    }
/*    static void read(ifstream &i, string &elem){

    }*/
};

template<typename T, typename P=persistence_traits<T> >
class pvector {
    vector<T> v;
    string filename;
public:
    typedef P persister;
    typedef typename vector<T>::iterator iterator;
    void writevector() {
        ofstream ofs(filename);
        iterator fst=v.begin(), lst=v.end();
        while(fst!=lst) persister::write(ofs,*fst++);
    }
    void readvector(){
        ifstream ifs(filename);
        for(;;) {
            T x; ifs >> x;
            if(!ifs.good())
                break;
            v.push_back(x);
        }
    }

    pvector(string fname) : filename(fname) {
        readvector();
    }
    ~pvector() {
        writevector();
    }
    void push_back(const T &el) {
        v.push_back(el);
    }
    void pop_back() {
        v.pop_back();
    }
    vector<T> get_vector(){
        return v;
    }
};

#endif //EX1_SHEET3_PVECTOR_H
