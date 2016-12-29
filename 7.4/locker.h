//
// Created by Rafael Kallis on 29.12.16.
//

#ifndef CPP_EXERCISES_LOCKER_H
#define CPP_EXERCISES_LOCKER_H

#include <string>
#include <exception>

/**
 * Locker class
 */
class Locker {
public:

    Locker(std::string filename);

    ~Locker();

private:

    std::string filename;

    void lock();

    void unlock();

};

struct FileNotFoundException : public std::runtime_error {
public:
    FileNotFoundException();
};

struct FileLockedException : public std::runtime_error {
public:
    FileLockedException();
};

#endif //CPP_EXERCISES_LOCKER_H
