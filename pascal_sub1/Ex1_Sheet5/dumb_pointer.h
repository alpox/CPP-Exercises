//
// Created by Pascal on 22.12.2016.
//

#ifndef EX1_SHEET5_DUMB_POINTER_H
#define EX1_SHEET5_DUMB_POINTER_H


template<typename T>
class dumb_pointer{
private:
    T* pointer;

public:
    dumb_pointer(T value){
        pointer = new T();
        *pointer = value;
    }

    T operator*() {
        return *pointer;
    }
};


#endif //EX1_SHEET5_DUMB_POINTER_H
