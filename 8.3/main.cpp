
#include "connect4.h"
#include "playfield.h"
#include "player.h"
#include "player_factory.h"
#include <iostream>

int main() {
    srand(time(NULL));

    numbered_player *player1;
    numbered_player *player2;

    bool player1_selected = false;
    do {
        std::cout << "Choose Player 1:" << std::endl << "(1) human" << std::endl << "(2) basic cpu" << std::endl << "(3) threaded cpu" << std::endl << "option: ";
        char input;
        std::cin >> input;

        switch(input){
            case '1': 
                player1 = player_factory::make_human(1);
                player1_selected = true;
                break;
            case '2':
                player1 = player_factory::make_basic_cpu(1);
                player1_selected = true;
                break;
            case '3':
                player1 = player_factory::make_threaded_cpu(1);
                player1_selected = true;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
                break;
        }
    } while(!player1_selected);

    bool player2_selected = false;
    do {
        std::cout << "Choose Player 2:" << std::endl << "(1) human" << std::endl << "(2) basic cpu" << std::endl << "(3) threaded cpu" << std::endl << "option: ";
        char input;
        std::cin >> input;

        switch(input){
            case '1': 
                player2 = player_factory::make_human(2);
                player2_selected = true;
                break;
            case '2':
                player2 = player_factory::make_basic_cpu(2);
                player2_selected = true;
                break;
            case '3':
                player2 = player_factory::make_threaded_cpu(2);
                player2_selected = true;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
                break;
        }
    } while(!player2_selected);

    playfield_impl field;
    connect4 game(field, player1, player2);
    game.start();

    delete player1;
    delete player2;
    return 0;
}
