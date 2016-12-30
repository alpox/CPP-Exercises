#include <iostream>
#include "apply_binary.h"

using namespace std;

struct add : binary_function<int, int, int>
{
    int operator()(int i, int p) const { return i + p; }
};
struct add2 : unary_function<int, int>
{
    int operator()(int i) const { return i + 2; }
};
struct add10 : unary_function<int, int>
{
    int operator()(int i) const { return i + 10; }
};

int main() {
    add fun1;
    add2 fun2;
    add10 fun3;
    auto binary_op = apply_binary<add, add2, add10>(fun1, fun2, fun3);
    cout << "Output: " << binary_op(5) << endl; // (5 + 2) + (5 + 10) = 22
    return 0;
}