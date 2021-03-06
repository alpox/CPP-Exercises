#include <iostream>

#include <float.h>
#include <sstream>
#include <algorithm>
#include <complex>
#include <cmath>
#include <stdexcept>

#include "pvector.h"

using namespace std;

template <typename T>
inline pair<T, T> getCalcValues(pvector<T> &rpnStack) {
    T first, second;
    second = rpnStack.back();
    rpnStack.pop_back();
    first = rpnStack.back();
    rpnStack.pop_back();
    return pair<T, T>(first, second);
};


template <typename T>
inline void printStack(pvector<T> &rpnStack) {
    for(int i = 0; i < rpnStack.size(); i++) {
        cout << (i+1) << ": " << rpnStack[i] << '\n';
    }
}

template<typename T>
bool operator<(const complex<T> &c1, const complex<T> &c2) {
	return std::abs(c1) < std::abs(c2);
}

template<typename T>
inline T mymin(T a, T b) {
	return a<b?a:b; // doesn't work for complex numbers
}

// template<typename c_type>
// inline complex<c_type> mymin(complex<c_type> a, complex<c_type> b) {
// 	throw std::invalid_argument("Complex numbers are not allowed.");
// }

template <typename T>
void RPN() {
    string filename = "testOutput.txt";

	pvector<T> rpnStack(filename);

	pair<T, T> values;
	bool stop = false;
	string line;


	printStack(rpnStack);

	cout << "Command: ";

	while(getline(cin, line)) {
		stringstream linestream(line);
		char cmd;
		T num;

		T cum;
		while (linestream >> cmd) {
			switch (cmd) {
				case 'n':
					linestream >> num;
					rpnStack.push_back(num);
					break;
				case 'd':
					rpnStack.pop_back();
					break;
				case 'q':
					return;
				case 'p':
					printStack(rpnStack);
					break;
				case 'm':
					if(rpnStack.size() < 2) {
						cout << "Too less items on the stack." << endl;
						break;
					}
					cum = *rpnStack.begin();
					try {
						for_each(rpnStack.begin(), rpnStack.end(), [&] (T &entry) { cum = mymin(cum, entry); });
					}
					catch(std::invalid_argument) {
						cout << "Tried to call minimum function with complex numbers. Do nothing." << endl;
						break;
					}
					rpnStack.push_back(cum);
					break;
				case '+':
					if(rpnStack.size() < 2) {
						cout << "Too less items on the stack." << endl;
						break;
					}
					values = getCalcValues(rpnStack);
					rpnStack.push_back(values.first + values.second);
					break;
				case '-':
					if(rpnStack.size() < 2) {
						cout << "Too less items on the stack." << endl;
						break;
					}
					values = getCalcValues(rpnStack);
					rpnStack.push_back(values.first - values.second);
					break;
				case '/':
					if(rpnStack.size() < 2) {
						cout << "Too less items on the stack." << endl;
						break;
					}
					values = getCalcValues(rpnStack);
					rpnStack.push_back(values.first / values.second);
					break;
				case '*':
					if(rpnStack.size() < 2) {
						cout << "Too less items on the stack." << endl;
						break;
					}
					values = getCalcValues(rpnStack);
					rpnStack.push_back(values.first * values.second);
					break;
				default:
					cout << "Invalid argument" << endl;
					break;
			}
		}
		printStack(rpnStack);
		cout << "Command: ";
	}
}

// complex numbers don't have ordering
int main() {
    RPN<complex<double>>();
    return 0;
}
