#include <iostream>

class Parent{
public:
    Parent(){
        std::cout << "Executed Parent constructor" << std::endl;
    }

    ~Parent(){
        std::cout << "Executed Parent destructor" << std::endl;
    }
};

class AnotherParent{
public:
    AnotherParent(){
        std::cout << "Executed AnotherParent constructor" << std::endl;
    }

    ~AnotherParent(){
        std::cout << "Executed AnotherParent destructor" << std::endl;
    }
};

class Child : public Parent{
public:
    Child(){
        std::cout << "Executed Child constructor" << std::endl;
    }

    ~Child(){
        std::cout << "Executed Child destructor" << std::endl;
    }
};

class AnotherChild : public AnotherParent, Parent{
public:
    AnotherChild(){
        std::cout << "Executed AnotherChild constructor" << std::endl;
    }

    ~AnotherChild(){
        std::cout << "Executed AnotherChild destructor" << std::endl;
    }
};

class OneMoreChild : public Parent, AnotherParent{
public:
    OneMoreChild(){
        std::cout << "Executed OneMoreChild constructor" << std::endl;
    }

    ~OneMoreChild(){
        std::cout << "Executed OneMoreChild destructor" << std::endl;
    }
};

void testDriverChild(){
    std::cout << "First test shows what happens if we inherit just from one class called Parent" << std::endl;
    Child();
}

void testDriverAnotherChild(){
    std::cout << std::endl;
    std::cout << "Second test shows what happens if we inherit from AnotherParent and Parent (in this order)" << std::endl;
    AnotherChild();
}

void testDriverOneMoreChild(){
    std::cout << std::endl;
    std::cout << "Third test shows what happens if we inherit from Parent and afterwards from AnotherParent" << std::endl;
    OneMoreChild();
}

void combinedTestDriver(){
    testDriverChild();
    testDriverAnotherChild();
    testDriverOneMoreChild();
}

int main() {
    combinedTestDriver();
    return 0;
}