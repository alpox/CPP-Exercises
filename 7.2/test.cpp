
#include "stack.h"
#include <iostream>
#include <cassert>

void test_unlimited_stack() {
	unlimited_stack sky_is_the_limit_stack(1);
	try {
		sky_is_the_limit_stack.push('a');
		sky_is_the_limit_stack.push('a');
	} catch (const std::exception &) {
		std::cout << "no exception expected" << std::endl;
		assert(false);
	}
}

void test_overflow() {
	static_stack s(1);
	try {
		s.push('a');
		s.push('a');
		std::cout << "expected overflow exception" << std::endl;
		assert(false);
	} catch (const overflow_exception &) {
		// ok
	} catch (const std::exception &) {
		std::cout << "expected overflow exception" << std::endl;
		assert(false);
	}
}

void test_underflow() {
	static_stack s;
	try {
		s.pop();
		std::cout << "expected undeflow exception" << std::endl;
		assert(false);
	} catch (const underflow_exception &) {
		// ok
	} catch (const std::exception &) {
		std::cout << "expected undeflow exception" << std::endl;
		assert(false);
	}
}

void test_push_pop() {
	static_stack s;
	try {
		s.push('h');
		if (s.pop() != 'h'){
			std::cout << "expected h as output" << std::endl;
			assert(false);
		}
	} catch (const std::exception &) {
		std::cout << "no exceptions expected" << std::endl;
		assert(false);
	}
}

int main() {
	test_push_pop();
	test_underflow();
	test_overflow();
	test_unlimited_stack();
	std::cout << "All tests passed" << std::endl;
	return 0;
}