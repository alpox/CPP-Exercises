//
// Created by Rafael Kallis on 29.12.16.
//

#include "locker.h"
#include <iostream>
#include <string>
#include <fcntl.h> // open()
#include <unistd.h> // close()
#include <cerrno>

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
    file_descriptor = open(filename.c_str(), O_RDWR | O_EXLOCK | O_NONBLOCK);
    if (file_descriptor == -1){
        switch(errno){
            case ENOENT: throw FileNotFoundException();
            case EAGAIN: throw FileLockedException();
            default: throw std::runtime_error("uncaught exception");
        }
        
    }
}

void Locker::unlock() {
    close(file_descriptor);
}

void Locker::write_file(const std::string& content) {
    if(write(file_descriptor, content.c_str(), content.length()) == -1){
        throw std::runtime_error("write failed");
    }
}

const std::string Locker::read_file() {
    std::string content = "";
    while(true){
        char buf[256];
        int bytes_read = read(file_descriptor, buf, 256);

        // nothing to read
        if (bytes_read == 0){
            break;

        // error
        } else if (bytes_read == -1){
            throw std::runtime_error("read failed");
        }
        content.append(buf, bytes_read);
    }
    return content;
}

FileNotFoundException::FileNotFoundException() : std::runtime_error("file not found") {}

FileLockedException::FileLockedException() : std::runtime_error("file locked") {}