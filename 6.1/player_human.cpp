
#include "player_human.h"

#include <iostream>

void player_human::printField(const playfield &field) {
    std::cout << std::endl;
    for(int p = 0; p < playfield::width; p++) {
        std::cout << "-----";
    }
    std::cout << std::endl;
    for(int y = 0; y < playfield::height; y++) {
        for(int x = 0; x < playfield::width; x++) {
            int sp = field.stoneat(x, y);
            char ch;
            switch(sp) {
                case playfield::player1:
                    ch = 'X';
                    break;
                case playfield::player2:
                    ch = 'O';
                    break;
                default:
                    ch = ' ';
                    break;
            }
            std::cout << "|" << " " << ch << " " << "|";
        }
        std::cout << std::endl;
    }

    for(int p = 0; p < playfield::width; p++) {
        std::cout << "-----";
    }
    std::cout << std::endl;
    for(int p = 0; p < playfield::width; p++) {
        std::cout << "  " << (char)('A' + p) << "  ";
    }
    std::cout << std::endl;
}

int player_human::play(const playfield &field) {
    printField(field);

    char input;

    std::cout << "Choose column (A-Z): ";

    do {
        std::cin >> input;

        if(input < 'A' || input > 'Z') {
            std::cout << "'" << input << "' is no valid column!" << std::endl;
            std::cout << "Please enter a valid column (A-Z): ";
            continue;
        }

        break;
    } while(true);

    return (int)input - 65;
}