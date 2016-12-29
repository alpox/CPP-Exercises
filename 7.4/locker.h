//
// Created by Rafael Kallis on 29.12.16.
//

#ifndef CPP_EXERCISES_LOCKER_H
#define CPP_EXERCISES_LOCKER_H

#include <string>

/**
 * Locker class
 */
class Locker {
public:
    Locker(std::string filename);
    ~Locker();
private:
    /**
     * Name of file to lock
     */
    std::string filename;
    void lock();
    void unlock();
};


#endif //CPP_EXERCISES_LOCKER_H
