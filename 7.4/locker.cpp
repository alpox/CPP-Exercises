//
// Created by Rafael Kallis on 29.12.16.
//

#include "locker.h"
#include <iostream>
#include <fstream>
#include <string>
#include <fcntl.h> // open()
#include <unistd.h> // close()
#include <cerrno>
#include <stdio.h>

Locker::Locker(std::string filename) : filename(filename) {
    lock();
}

Locker::~Locker() {
    unlock();
}

/**
 *  Locks the file with read/write access, holds an exclusive lock
 *
 *  @throws FileNotFoundException: file not found
 *  @throws FileLockedException: file locked by another lock 
 */
void Locker::lock() {
    std::string lock_filename(filename);
    lock_filename.append(".lock");

    std::ifstream file_exists_ifs(filename);
    if (!file_exists_ifs.good()){
        throw FileNotFoundException();
    }
    file_exists_ifs.close();

    std::ifstream lock_exists_ifs(lock_filename);
    if (lock_exists_ifs.good()){
        throw FileLockedException();
    }
    lock_exists_ifs.close();

    std::ofstream create_lock_file_ofs(lock_filename);
    create_lock_file_ofs.close();
}

void Locker::unlock() {
    std::string lock_filename(filename);
    lock_filename.append(".lock");
    std::remove(lock_filename.c_str());
}

FileNotFoundException::FileNotFoundException() : std::runtime_error("file not found") {}

FileLockedException::FileLockedException() : std::runtime_error("file locked") {}