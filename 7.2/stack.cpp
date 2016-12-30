
#include "stack.h"

static_stack::static_stack(int max_size) : max_size(max_size), buf(new char[max_size]), idx(buf) {}
static_stack::~static_stack() { delete[] buf; }

void static_stack::push(char elem){
	if (idx == buf + max_size) throw overflow_exception();
	*(idx++) = elem;
}

char static_stack::pop(){
	if (idx == buf) throw underflow_exception();
	return *(--idx);
}

unlimited_stack::unlimited_stack(int init_size) : static_stack(init_size), init_size(init_size) {}

void unlimited_stack::push(char elem){
	try {
		static_stack::push(elem);
	} catch (const overflow_exception &) {
		char* buf_ptr = buf;

		// double size
		max_size *= 2;

		// allocate new buf
		char* new_buf = new char[max_size];
		char* new_buf_ptr = new_buf;

		// copy old buf to newly allocated buf
		while(buf_ptr <= idx) *(new_buf_ptr++) = *(buf_ptr++);

		// delete old buf
		delete[] buf;

		// replace buf and idx with the new goodies
		buf = new_buf;
		idx = new_buf_ptr;

		// now where we have enough space, we can push elem
		push(elem);
	}
}

char unlimited_stack::pop(){
	if (idx == buf) throw underflow_exception();
	return *(--idx);
}

overflow_exception::overflow_exception() : std::runtime_error("stack overflow") {};

underflow_exception::underflow_exception() : std::runtime_error("stack underflow") {};