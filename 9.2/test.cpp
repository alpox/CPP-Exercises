
#include "formatstream.h"
#include <iostream>
#include <sstream>
#include <cassert>
#include <string>


void test_double_quote_in_single_quote(){
    std::stringstream ss;
    formatstream fs(ss);
    ss << "std::string func(){\nreturn \'{\n\"test\"\n}\';\n}" << std::endl;
    // std::cout << ss.str();

    std::string expected("std::string func(){\n\treturn \'{\n\t\"test\"\n\t}\';\n}\n");
    assert(expected.compare(ss.str()) == 0);
}

void test_single_quote_in_double_quote(){
    std::stringstream ss;
    formatstream fs(ss);
    ss << "std::string func(){\nreturn \"{\n\'test\'\n}\";\n}" << std::endl;
    // std::cout << ss.str();

    std::string expected("std::string func(){\n\treturn \"{\n\t\'test\'\n\t}\";\n}\n");
    assert(expected.compare(ss.str()) == 0);
}

void test_double_quote(){
    std::stringstream ss;
    formatstream fs(ss);
    ss << "std::string func(){\nreturn \"{\ntest\n}\";\n}" << std::endl;
    // std::cout << ss.str();

    std::string expected("std::string func(){\n\treturn \"{\n\ttest\n\t}\";\n}\n");
    assert(expected.compare(ss.str()) == 0);
}

void test_single_quote(){
    std::stringstream ss;
    formatstream fs(ss);
    ss << "std::string func(){\nreturn \'{\ntest\n}\';\n}" << std::endl;
    // std::cout << ss.str();

    std::string expected("std::string func(){\n\treturn \'{\n\ttest\n\t}\';\n}\n");
    assert(expected.compare(ss.str()) == 0);
}

void test_brackets(){
    std::stringstream ss;
    formatstream fs(ss);
    ss << "var array = [1,\n2];" << std::endl;
    // std::cout << ss.str();

    std::string expected("var array = [1,\n\t2];\n");
    assert(expected.compare(ss.str()) == 0);
}

void test_paranthesis(){
    std::stringstream ss;
    formatstream fs(ss);
    ss << "void func(void*,\nvoid*);" << std::endl;
    // std::cout << ss.str();

    std::string expected("void func(void*,\n\tvoid*);\n");
    assert(expected.compare(ss.str()) == 0);
}

void test_curly_bracket(){
    std::stringstream ss;
    formatstream fs(ss);
    ss << "void func(){\nreturn;\n}" << std::endl;
    // std::cout << ss.str();

    std::string expected("void func(){\n\treturn;\n}\n");
    assert(expected.compare(ss.str()) == 0);
}

int main(){
    test_curly_bracket();
    test_paranthesis();
    test_brackets();
    test_single_quote();
    test_double_quote();
    test_double_quote_in_single_quote();
    std::cout << "All tests passed" << std::endl;
    return 0;
}