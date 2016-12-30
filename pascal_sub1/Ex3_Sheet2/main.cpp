#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

void RPN(){
	
	string command;
	vector<int> v;
	char val;
	int counter = 0;
	int number;
	
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
			int x,y;
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
		}		
		vector<int>::iterator first = v.begin(), last = v.end();
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
	RPN();
	return 0;
}
