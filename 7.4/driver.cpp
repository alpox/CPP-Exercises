//
// Created by Rafael Kallis on 29.12.16.
//

#include "locker.h"
#include <iostream>
#include <unistd.h>

int main() {

    try {
        Locker locked_file("my_file");

        std::string content2 = locked_file.read_file();
        std::string content = "bla ";
        locked_file.write_file(content);

        // Locker not_existing_file_lock("not_existing_file");
        // Locker locked_file_lock("my_file");
    } catch (const FileNotFoundException &e) {
        std::cout << e.what() << std::endl;
    } catch (const FileLockedException &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}