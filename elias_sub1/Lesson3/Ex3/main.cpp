#include <iostream>

#include <limits>
#include <sstream>

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
inline T mymin(T a, T b) {
    return a<b?a:b;
}

template <typename T>
void RPN() {
    pvector<T> rpnStack("testOutput.txt");
    pair<T, T> values;
    bool stop = false;
    string line;


    printStack(rpnStack);

    cout << "Command: ";

    while(getline(cin, line)) {
        stringstream linestream(line);
        char cmd;
        T num;

        int cum;
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
                case 'm':
                    if(rpnStack.size() < 2) {
                        cout << "Too less items on the stack." << endl;
                        break;
                    }
                    cum = INT_MAX;
                    for_each(rpnStack.begin(), rpnStack.end(), [&] (T &entry) { cum = mymin(cum, entry); });
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

int main() {
    RPN<int>();
    return 0;
}