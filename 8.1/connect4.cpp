
#include "connect4.h"

connect4::connect4(playfield_impl &field, player *player1, player *player2) : field(field), player1(player1), player2(player2), current_player((rand() % 2 == 0) ? player1 : player2) {};

void connect4::start() {

    // Enter game loop
    while(true) {

        int col = current_player->play(field);
        bool win = field.set_stone_in_column(current_player_number(), col);

        if(win) {
            field.print();
            std::cout << "Player " << current_player_number() << " won the game!" << std::endl;
            break;
        }

        if(field.is_full()) {
            field.print();
            std::cout << "Field is full. Draw." << std::endl;
            break;
        }

        change_player();
    }
}

void connect4::change_player() {
    current_player = (current_player == player2) ? player1 : player2;
}

int connect4::current_player_number() {
    return (current_player == player1) ? 1 : 2;
}
