#include <iostream>
#include <string>
#include <fstream>
#include "pset.h"
#include "pvector.h"

using namespace std;

int main() {
    string filename("textfile.txt");
    pset<int> ps(filename);
    ps.remove(234);
    cout << ps.get_set().size();
    return 0;
}