#ifndef CONNECT4_H_
#define CONNECT4_H_

#include "playfield.h"
#include "playfield_impl.h"
#include "player.h"

class connect4 {
private:
    playfield_impl *field;
    player *player1;
    player *player2;

    player *currentPlayer;

private:
    void handleWin(player *player);
    void printField();
    
    // ChangePlayer returns the number of the new player
    int changePlayer();
public:
    connect4(playfield_impl *field, player *player1, player *player2):
        field(field), player1(player1), player2(player2), currentPlayer(player1) {};
    
    void start();
};

#endif // CONNECT4_H_
