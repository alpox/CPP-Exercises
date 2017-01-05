
#ifndef CONNECT4_H_
#define CONNECT4_H_

#include "player.h"
#include "playfield.h"
#include <string>
#include <iostream>

class connect4 {
public:
    connect4(playfield_impl &field, player *player1, player *player2);
    void start();
private:
    playfield_impl field;
    player *player1;
    player *player2;

    player *current_player;
    
    // toggles current_player from player1 to player2 and vice versa
    void change_player();

    // returns 1 if corrent_player is player1 and 2 if current_player is player2
    int current_player_number();
};

#endif // CONNECT4_H_
