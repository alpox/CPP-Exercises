
#ifndef STACK_H
#define STACK_H

#include <stdexcept>

// stack base class
struct stack {
public:
	virtual void push(char elem) = 0;
	virtual char pop() = 0;
};

// static stack
struct static_stack : public stack {
public:
	static_stack(int max_size = 256);
	~static_stack();

	void push(char elem);
	char pop();
protected:
	char* buf;
	char* idx;
	int max_size;
};

// growing stack
struct unlimited_stack : public static_stack {
public:
	unlimited_stack(int init_stack_size = 256);

	void push(char elem);
	char pop();
private:
	int init_size;
};

// thrown if stack is full
struct overflow_exception : public std::runtime_error {
public:
	overflow_exception();
};

// thrown if stack is empty
struct underflow_exception : public std::runtime_error {
public:
	underflow_exception();
};

#endif