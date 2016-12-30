//
// Created by Rafael Kallis on 29.12.16.
//

#include "locker.h"
#include <iostream>
#include <unistd.h>

int main() {

    try {
        Locker lock("my_file");

        // Locker not_existing_file_lock("not_existing_file");
        // Locker locked_file_lock("my_file");
    } catch (const FileNotFoundException &e) {
        std::cout << e.what() << std::endl;
    } catch (const FileLockedException &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
