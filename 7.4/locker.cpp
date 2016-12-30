//
// Created by Rafael Kallis on 29.12.16.
//

#include "locker.h"
#include <fstream>
#include <string>
#include <stdio.h>

Locker::Locker(std::string filename, int flags) : filename(filename), flags(flags) {
    lock();
}

Locker::~Locker() {
    unlock();
}

void Locker::lock() {

    // check if file exists
    std::ifstream file_exists_ifs(filename);
    if (!file_exists_ifs.good()){
        if (flags & CREATE_IF_NOT_EXISTS){
            std::ofstream create_file_ofs(filename);
            create_file_ofs.close();        
        } else {
            throw FileNotFoundException();
        }
    }
    file_exists_ifs.close();

    // check if lock already exists
    std::ifstream lock_exists_ifs(get_lock_filename());
    if (lock_exists_ifs.good()){
        throw FileLockedException();
    }
    lock_exists_ifs.close();

    // create lock file
    std::ofstream create_lock_file_ofs(get_lock_filename());
    create_lock_file_ofs.close();
}

void Locker::unlock() {
    
    if (std::remove(get_lock_filename().c_str()) == -1){
        throw std::runtime_error("uncaught exception");
    }
    if (flags & DELETE_FILE_ON_DESTRUCT && (std::remove(filename.c_str()) == -1)) {
        throw std::runtime_error("uncaught exception");
    }
}

std::string Locker::get_lock_filename(){
    std::string lock_filename(filename);
    lock_filename.append(".lock");
    return lock_filename;
}

FileNotFoundException::FileNotFoundException() : std::runtime_error("file not found") {}

FileLockedException::FileLockedException() : std::runtime_error("file locked") {}