//
// Created by Rafael Kallis on 29.12.16.
//

#include "locker.h"
#include <iostream>
#include <string>

Locker::Locker(std::string filename) : filename(filename) {
    lock();
}

Locker::~Locker() {
    unlock();
}

void Locker::lock() {
    std::cout << "lock() " << filename << std::endl;
}

void Locker::unlock() {
    std::cout << "unlock() " << filename << std::endl;
}