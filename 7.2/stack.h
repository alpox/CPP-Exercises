
#ifndef STACK_H
#define STACK_H

#include <stdexcept>

struct stack {
public:
	stack();
	~stack();

	void push(int elem);
	int pop();
private:
	int* buf;
	int* idx;
	int max = 256;
};

struct overflow_exception : public std::runtime_error {
public:
	overflow_exception();
};

#endif