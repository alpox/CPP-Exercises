
#include "connect4.h"

#include <string>
#include <cassert>
#include <iostream>

void connect4::start() {
    assert(field != NULL);
    assert(player1 != NULL);
    assert(player2 != NULL);

    int player = 1;

    if(currentPlayer == NULL) currentPlayer = player1;

    player = currentPlayer == player1 ? 1 : 2;

    printField();

    // Enter game loop
    while(true) {

        int col = currentPlayer->play(*field);
        bool win = field->setStoneInColumn(player, col);

        printField();

        if(win) {
            handleWin(currentPlayer);
            break;
        }

        if(field->isFull()) {
            std::cout << "Field is full. Draw." << std::endl;
            break;
        }
        player = changePlayer();
    }
}

int connect4::changePlayer() {
    currentPlayer = currentPlayer == player1 ? player2 : player1;
    return currentPlayer == player1 ? 1 : 2;
}

void connect4::printField() {
    std::cout << std::endl;
    for(int p = 0; p < playfield::width; p++) {
        std::cout << "-----";
    }
    std::cout << std::endl;
    for(int y = 0; y < playfield::height; y++) {
        for(int x = 0; x < playfield::width; x++) {
            int sp = field->stoneat(x, y);
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

void connect4::handleWin(player *who) {
    who = who == NULL ? currentPlayer : who;

    std::string winPlayer = "Player 1";
    
    if(who == player2) winPlayer = "Player 2";

    std::cout << winPlayer << " won the game!" << std::endl;
}
