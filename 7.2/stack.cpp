
#include "stack.h"

stack::stack() : buf(new int[max]), idx(buf) {}
stack::~stack() { delete[] buf; }

void stack::push(int elem){
	if (idx == buf + sizeof(buf)) throw overflow_exception();
}

int stack::pop(){
	return 0;
}

overflow_exception::overflow_exception() : std::runtime_error("stack overflow") {};