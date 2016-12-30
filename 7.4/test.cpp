//
// Created by Rafael Kallis on 29.12.16.
//

#include "locker.h"
#include <iostream>
#include <fstream>
#include <cassert>

void test_delete_file_on_destruct(){
	std::ofstream create_file("non_existing_file");
	create_file.close();
	try {
		Locker lock("non_existing_file", DELETE_FILE_ON_DESTRUCT);
	} catch (const FileNotFoundException &e) {
		std::cout << "no exception expected" << std::endl;
		assert(false);
	} catch (const std::exception &) {
		std::cout << "no exception expected" << std::endl;
		assert(false);
	}

	std::ifstream check_if_file_exists("non_existing_file");
	if (check_if_file_exists.good()){
			check_if_file_exists.close();
			std::remove("non_existing_file");
			std::cout << "no remaining file expected" << std::endl;
			assert(false);	
	}
}

void test_create_if_not_exists(){
	try {
		Locker lock("non_existing_file", CREATE_IF_NOT_EXISTS);
	} catch (const FileNotFoundException &e) {
		std::cout << "no exception expected" << std::endl;
		assert(false);
	} catch (const std::exception &) {
		std::cout << "no exception expected" << std::endl;
		assert(false);
	}

	std::remove("non_existing_file");
}

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
	test_create_if_not_exists();
	std::cout << "All tests passed" << std::endl;
	return 0;
}