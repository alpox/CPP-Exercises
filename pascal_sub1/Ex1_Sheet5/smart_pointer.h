//
// Created by Pascal on 22.12.2016.
//

#ifndef EX1_SHEET5_SMART_POINTER_H
#define EX1_SHEET5_SMART_POINTER_H


template<typename T>
class smart_pointer{
private:
    T* pointer;
    int* references = new int(0);
public:
    smart_pointer(const T &value){
        pointer = new T();
        *pointer= value;
        *references = 1;
    }
    ~smart_pointer(){
        (*references)--;
        if(*references == 0){
            delete pointer;
            delete references;
        }
    }
    smart_pointer(const smart_pointer &other){
        pointer = other.pointer;
        (*other.references)++;
        references = other.references;
    }
    T operator*(){
        return *pointer;
    }
    void operator=(const smart_pointer<T> &other){
        (*references)--;
        pointer = other.pointer;
        references = other.references;
        (*references)++;
    }
    T* operator->(){
        return pointer;
    }

    int counter(){
        return *references;
    }
};


#endif //EX1_SHEET5_SMART_POINTER_H
