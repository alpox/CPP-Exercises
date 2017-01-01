
#include "connect4.h"
#include "playfield_impl.h"
#include "player_comp.h"

int main() {
    srand(time(NULL));

    playfield_impl field;
    player_comp player1(1);
    player_comp player2(2);
    connect4 game(&field, &player1, &player2);

    game.start();
    return 0;
}
