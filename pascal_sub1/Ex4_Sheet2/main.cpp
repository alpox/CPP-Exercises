#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "fracOp.h"
#include "fraction.h"
#include "fracPrint.h"

using namespace std;

template<typename T>
inline T mymin(T a, T b){
	return a<b?a:b;
}

template<typename T>
void RPN(){
	
	string command;
	vector<T> v;
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
				v.push_back(number);
			}
			if(val == 'd' && !v.empty()){
				v.pop_back();
			}
			if(val == 'q'){
				break;
			}
			T x,y;
			if(val == '+' && v.size()>1){
				x = v.back();
				v.pop_back();
				y = v.back();
				v.pop_back();
				v.push_back(x+y);
			}
			if(val == '-' && v.size()>1){
				x = v.back();
				v.pop_back();
				y = v.back();
				v.pop_back();
				v.push_back(y-x);
			}
			if(val == '*' && v.size()>1){
				x = v.back();
				v.pop_back();
				y = v.back();
				v.pop_back();
				v.push_back(x*y);
			}
			if(val == '/' && v.size()>1){
				x = v.back();
				v.pop_back();
				y = v.back();
				v.pop_back();
				v.push_back(y/x);
			}
			if(val == 'm' && v.size()>1){
				x = v.back();
				v.pop_back();
				y = v.back();
				v.pop_back();
				v.push_back(mymin(x,y));
			}
		}		
		typename vector<T>::iterator first = v.begin(), last = v.end();
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
