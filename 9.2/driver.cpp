
#include "formatstream.h"
#include <iostream>

int main(){

    formatstream fs(std::cout);

    // curly brackets
    std::cout << "void func(){\nreturn;\n}" << std::endl;

    // parenthesis
    std::cout << "void func(void*,\nvoid*);" << std::endl;

    // brackets
    std::cout << "var array = [1,\n2];" << std::endl;

    // single quote
    std::cout << "std::string func(){\nreturn \'{\ntest\n}\';\n}" << std::endl;

    // double quotes
    std::cout << "std::string func(){\nreturn \"{\ntest\n}\";\n}" << std::endl;

    return 0;
}