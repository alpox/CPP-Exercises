#include <iostream>

using namespace std;

inline int factorial(int n){
	if(n>0){
		return n*factorial(n-1);
	}else{
		return 1;
	}
}

int main(int argc, char** argv) {
	cout << factorial(5);
	return 0;
}
