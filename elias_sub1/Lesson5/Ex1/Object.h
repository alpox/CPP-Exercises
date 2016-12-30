//
// Created by Elias on 01.11.16.
//

#ifndef EX1_OBJECT_H
#define EX1_OBJECT_H

#include <iostream>
#include <string>

class Object {
    int number;
public:

    Object(int i) : number(i) {};

    int description() const {
        return number;
    }

    friend std::ostream &operator<<(std::ostream &stream, const Object &ob) {
        stream << ob.number;
        return stream;
    }

    int method1() const {
        return number + 1;
    }

    int method2() const {
        return number + 2;
    }

    int method3() const {
        return number + 3;
    }
};

#endif //EX1_OBJECT_H
