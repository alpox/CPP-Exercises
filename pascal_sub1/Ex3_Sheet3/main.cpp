#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "pvector.h"
#include "fraction.h"
#include "fracOp.h"
#include "fracPrint.h"
#include <algorithm>

using namespace std;

template<typename T>
void RPN(){
	
	string command;
	string filename = "storage.txt";
	pvector<T> pv(filename.c_str());
	char val;
	int counter = 0;
	T number;
	
	while(true){
		cout << "Enter command: ";
		getline(cin,command);
		istringstream is(command);
		while(is >> val){		
			if(val == 'n'){
				is >> number;
				pv.push_back(number);
			}
			if(val == 'd' && !pv.v.empty()){
				pv.pop_back();
			}
			if(val == 'q'){
				break;
			}
			T x,y;
			if(val == '+' && pv.v.size()>1){
				x = pv.v.back();
				pv.pop_back();
				y = pv.v.back();
				pv.pop_back();
				pv.push_back(x+y);
			}
			if(val == '-' && pv.v.size()>1){
				x = pv.v.back();
				pv.pop_back();
				y = pv.v.back();
				pv.pop_back();
				pv.push_back(y-x);
			}
			if(val == '*' && pv.v.size()>1){
				x = pv.v.back();
				pv.pop_back();
				y = pv.v.back();
				pv.pop_back();
				pv.push_back(x*y);
			}
			if(val == '/' && pv.v.size()>1){
				x = pv.v.back();
				pv.pop_back();
				y = pv.v.back();
				pv.pop_back();
				pv.push_back(y/x);
			}
			if(val == 'm' && pv.v.size()>1){
                T my_min_val = *pv.v.begin();
				for_each(pv.v.begin(),pv.v.end(),[&](T &cur){my_min_val=my_min_val<cur?my_min_val:cur;});
                cout << "Minimum is: " << my_min_val << endl;
			}
		}		
		typename vector<T>::iterator first = pv.v.begin(), last = pv.v.end();
		counter = 0;
		
		while(first!=last){
			cout << ++counter << ": " << *first++ << endl;
		}
		if(val == 'q'){
			break;
		}
	}
}

int main(int argc, char** argv) {
	RPN<fraction>();
	return 0;
}