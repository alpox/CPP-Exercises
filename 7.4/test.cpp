//
// Created by Rafael Kallis on 29.12.16.
//

#include "locker.h"
#include <iostream>
#include <cassert>

void test_locked_file() {
	try {
		Locker lock("my_file");
		Locker lock2("my_file");
		std::cout << "FileLockedException expected" << std::endl;
		assert(false);
	} catch (const FileLockedException &e) {
		// ok
	} catch (const std::exception &) {
		std::cout << "FileLockedException expected" << std::endl;
		assert(false);
	}
}

void test_non_existing_file() {
	try {
		Locker lock("non_existing_file");
		std::cout << "FileNotFoundException expected" << std::endl;
		assert(false);
	} catch (const FileNotFoundException &e) {
		// ok
	} catch (const std::exception &) {
		std::cout << "FileNotFoundException expected" << std::endl;
		assert(false);
	}
}

void test_lock() {
	try {
		Locker lock("my_file");
	} catch (const std::exception &) {
		std::cout << "no exception expected" << std::endl;
		assert(false);
	}
}

int main(){
	test_lock();
	test_non_existing_file();
	test_non_existing_file();
	std::cout << "All tests passed" << std::endl;
	return 0;
}