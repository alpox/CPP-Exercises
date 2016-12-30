#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "pvector.h"
using namespace std;

int main(int argc, char** argv) {
	string filename = "randomString.txt";
	pvector<int> pv(filename);
	return 0;
}

