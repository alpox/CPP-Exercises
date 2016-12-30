#include <iostream>
#include "Object.h"
#include "dumb_pointer.h"
#include "smart_pointer.h"

using namespace std;


void print(smart_pointer<Object> p) {
    cout << p.counter() << ": " << *p << endl;
}

void foo() {
    Object *o1=new Object(1);
    Object *o2=new Object(2);
    smart_pointer<Object> p(o1);
    cout << p.counter() << endl;
// let's create our 1st object
// let's create our 2nd object
// ref counter is 1 for 1st object
// displays 1
// another smart pointer pointing to o1 (overload copy constructor)
    smart_pointer<Object> q(p);
// counter() returns how many smart pointers refer to the object
    cout << p.counter() << endl;
    cout << q.counter() << endl;
    smart_pointer<Object> r(o2);
    cout << r.counter() << endl;
// displays 2
// displays 2
// ref counter is 1 for 2nd object
// displays 1
// overload the assignment operator
    q=r;
    cout << p.counter() << endl;
    cout << q.counter() << endl;
    cout << r.counter() << endl;
// decrease counter for 1st object and
// increase counter for 2nd object
// displays 1
// displays 2
// displays 2
    print(p);
    print(q);
    print(r);
// ensure that the above 3 functions, don’t delete the objects
// displays 2, and the 1st object
// displays 3, and the 2nd object
// displays 3, and the 2nd object
// overload operator*
    cout << *p << *r << endl; // display 1st and 2nd object
    // overload operator->
    cout << p->method1() << q->method2() << r->method3() << endl;
    // invoke method1 on 1st object and
    // invoke method2 on 2nd object and
    // invoke method3 on 2nd object
} // now the destructors of p, q, and r are called, make sure that 1st
// and 2nd object is each deleted once
// (i.e., when the counter reaches 0)

int main() {
    // Dumb pointer test
    Object *ob = new Object(42);

    dumb_pointer<Object> pob(ob);

    cout << "Start dumb_pointer tests" << endl;

    cout << *pob << endl;
    cout << pob->description() << endl;

    cout << "End dumb_pointer tests" << endl;

    cout << "Start smart_pointer tests" << endl;
    foo();
    cout << "End smart_pointer tests" << endl;
}