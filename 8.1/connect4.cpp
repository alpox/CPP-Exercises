
#include "connect4.h"

connect4::connect4(playfield_impl &field, numbered_player &player1, numbered_player &player2) : field(field), player1(player1), player2(player2), current_player((rand() % 2 == 0) ? &player1 : &player2) {};

void connect4::start() {

    // Enter game loop
    while(true) {

        int col = current_player->play(field);
        bool win = field.setStoneInColumn(current_player->get_number(), col);

        if(win) {
            field.print();
            std::cout << "Player " << current_player->get_number() << " won the game!" << std::endl;
            break;
        }

        if(field.isFull()) {
            field.print();
            std::cout << "Field is full. Draw." << std::endl;
            break;
        }

        change_player();
    }
}

void connect4::change_player() {
    current_player = (*current_player == player2) ? &player1 : &player2;
}
