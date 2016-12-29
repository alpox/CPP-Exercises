//
// Created by Rafael Kallis on 29.12.16.
//

#include "locker.h"
#include <iostream>

int main(){

	try {
		Locker my_lock("my_file");
	} catch (const std::exception &) {
		std::cout << "Exception" << std::endl;
	}

	return 0;
}