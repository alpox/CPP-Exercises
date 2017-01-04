
#ifndef CONNECT4_H_
#define CONNECT4_H_

#include "player.h"
#include "playfield.h"
#include <string>
#include <iostream>

class connect4 {
public:
    connect4(playfield_impl &field, numbered_player &player1, numbered_player &player2);
    void start();
private:
    playfield_impl field;
    numbered_player &player1;
    numbered_player &player2;

    numbered_player *current_player;
    
    // ChangePlayer returns the number of the new player
    void change_player();
};

#endif // CONNECT4_H_
