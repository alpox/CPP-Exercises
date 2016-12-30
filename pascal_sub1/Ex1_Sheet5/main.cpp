#include <iostream>
#include "dumb_pointer.h"
#include "smart_pointer.h"
#include "Object.h"

void print(smart_pointer<Object> p) {
    std::cout << p.counter() << ": " << (*p).getValue() << std::endl;
}

void foo() {
    Object *o1=new Object(1);         // let's create our 1st object
    Object *o2=new Object(2);         // let's create our 2nd object
    smart_pointer<Object> p(*o1);      // ref counter is 1 for 1st object
    std::cout << p.counter() << std::endl;      // displays 1
    smart_pointer<Object> q(p);      // another smart pointer that points to o1 (overload copy constructor)
    std::cout << p.counter() << std::endl;      // displays 2 (two smart pointers refer to o1)
    std::cout << q.counter() << std::endl;      // displays 2 (two smart pointers refer to o1)
    smart_pointer<Object> r(*o2);      // ref counter is 1 for 2nd object
    std::cout << r.counter() << std::endl;      // displays 1
    q=r;                              // decrease counter for 1st object and
                                      // increase counter for 2nd object (overload assignment operator)
    std::cout << p.counter() << std::endl;      // displays 1
    std::cout << q.counter() << std::endl;      // displays 2
    std::cout << r.counter() << std::endl;      // displays 2
    print(p);                         // displays 2, and the 1st object, don't delete the object pointed to by p
    print(q);                         // displays 3, and the 2nd object, don't delete the object pointed to by q
    print(r);                         // displays 3, and the 2nd object, don't delete the object pointed to by r
    std::cout << "Value of p: " << (*p).getValue() << std::endl << "Value of r: " << (*r).getValue() << std::endl;         // display 1st and 2nd object (overload operator*)
    std::cout << "Method 1 on p: " << p->method1() << std::endl     // invoke method1 on 1st object and
              << "Method 2 on q: " << q->method2() << std::endl     // invoke method2 on 2nd object and
              << "Method 3 on r: " << r->method3() << std::endl;    // invoke method3 on 2nd object (overload operator->)
    }
    // now the destructors of p, q, and r are called, make sure that 1st
    //and 2nd object is each deleted once (i.e., when the counter reaches 0)

int main(){
    foo();
    return 0;
}