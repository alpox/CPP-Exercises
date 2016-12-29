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

    /**
     *  Locks the file with read/write access, holds an exclusive lock
     *
     *  @throws FileNotFoundException: file not found
     *  @throws FileLockedException: file locked by another lock 
     */
    void lock();

    /**
     *  @throws std::runtime_error: uncaught exception while removing lock
     */
    void unlock();

    /**
     * @returns: the lock filename of the locked file
     */
    std::string get_lock_filename();

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
