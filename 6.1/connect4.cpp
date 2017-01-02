
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

    // Enter game loop
    while(true) {

        int col = currentPlayer->play(*field);
        bool win = field->setStoneInColumn(player, col);

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

void connect4::handleWin(player *who) {
    who = who == NULL ? currentPlayer : who;

    std::string winPlayer = "Player 1";
    
    if(who == player2) winPlayer = "Player 2";

    std::cout << winPlayer << " won the game!" << std::endl;
}
