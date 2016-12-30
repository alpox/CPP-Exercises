#ifndef PVECTOR_H
#define PVECTOR_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

template<typename T>
class pvector{
		string filename;
	public:
		vector<T> v;
	public:
		pvector(string fname):filename(fname){ 
			readvector(); 
		}
		~pvector() { 
			writevector(); 
		}
		void push_back(const T &el){
			v.push_back(el); 
		}
		void pop_back() {
			v.pop_back(); 
		}
		void readvector() {
			ifstream ifs(filename.c_str());
			for(;;) {
				T x; 
				ifs >> x; 
				if(!ifs.good()) 
					break;
				v.push_back(x);
			}
		}
		void writevector() {
			ofstream ofs(filename.c_str());
			typename vector<T>::iterator fst=v.begin(), lst=v.end();
			while(fst!=lst) 
				ofs << *fst++ << endl;
		}
};

#endif
