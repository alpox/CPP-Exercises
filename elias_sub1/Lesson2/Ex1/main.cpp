#include <iostream>
#include "pvector.h"

using namespace std;
int main() {

    pvector<string> chars("test.txt");
    cout << chars << endl;
    chars.push_back("blabla");
    return 0;
}