//
// Created by Pascal on 22.12.2016.
//

#ifndef EX1_SHEET5_OBJECT_H
#define EX1_SHEET5_OBJECT_H


class Object{
private:
    int value;

public:
    Object(){
        value=0;
    }

    Object(int value){
        this->value = value;
    }

    int method1(){
        return 1;
    }

    int method2(){
        return 2;
    }

    int method3(){
        return 3;
    }

    int getValue(){
        return this->value;
    }
};


#endif //EX1_SHEET5_OBJECT_H
