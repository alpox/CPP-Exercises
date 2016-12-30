#include <iostream>
#include <assert.h>
#include <sstream>
#include <stack>

#include "fraction.h"


using namespace std;


void testFractionAddition() {
    fraction f(2, 4);
    fraction f2(5, 6);

    fraction solution = f + f2;

    assert(solution.getNumerator() == 4);
    assert(solution.getDenominator() == 3);
}
void testFractionSubtraction() {
    fraction f(2, 4);
    fraction f2(2, 6);

    fraction solution = f - f2;

    assert(solution.getNumerator() == 1);
    assert(solution.getDenominator() == 6);
}

void testFractionOutOperator() {
    fraction f(2, 4);
    stringstream stream;
    stream << f;

    assert(stream.str() == "(2/4)");
}

void testFractionInOperator() {
    fraction f;
    stringstream("(4/6)") >> f;

    assert(f.getNumerator() == 4);
    assert(f.getDenominator() == 6);
}


void repl() {
    bool stop;
    char op;
    string input;
    stack<fraction> inStack;

    while(!stop) {
        cin >> op;

        switch(op) {
            case 'n': {
                fraction f;
                cin >> f;
                inStack.push(f);
                break;
            }
            case 'd':
                inStack.pop();
                break;
            case 'q':
                stop = true;
                break;
            case 'p':
                if(inStack.empty()) {
                    cout << "The stack is empty." << endl;
                    break;
                }
                for (stack<fraction> dump = inStack; !dump.empty(); dump.pop())
                    cout << dump.top() << endl;
                break;
            case '+': {
                if(inStack.size() < 2) {
                    cout << "Not enough fractions on the stack." << endl;
                    break;
                }
                fraction f1 = inStack.top();
                inStack.pop();
                fraction f2 = inStack.top();
                inStack.pop();
                cout << (f1 + f2) << endl;
                break;
            }
            case '-': {
                if(inStack.size() < 2) {
                    cout << "Not enough fractions on the stack." << endl;
                    break;
                }
                fraction sub1 = inStack.top();
                inStack.pop();
                fraction sub2 = inStack.top();
                inStack.pop();
                cout << (sub1 - sub2) << endl;
                break;
            }
            case '/': {
                if(inStack.size() < 2) {
                    cout << "Not enough fractions on the stack." << endl;
                    break;
                }
                fraction div1 = inStack.top();
                inStack.pop();
                fraction div2 = inStack.top();
                inStack.pop();
                cout << (div1 / div2) << endl;
                break;
            }
            case '*': {
                if(inStack.size() < 2) {
                    cout << "Not enough fractions on the stack." << endl;
                    break;
                }
                fraction mul1 = inStack.top();
                inStack.pop();
                fraction mul2 = inStack.top();
                inStack.pop();
                cout << (mul1 * mul2) << endl;
                break;
            }
            default: cout << "This operation is not allowed!" << endl;
        }
    }
}

int main() {
    testFractionAddition();
    testFractionSubtraction();
    testFractionOutOperator();
    testFractionInOperator();
    cout << "All automated test cases succeeded" << endl;
    repl();
    return 0;
}