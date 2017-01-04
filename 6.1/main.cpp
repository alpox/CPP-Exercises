
#include "connect4.h"
#include "playfield.h"
#include "player.h"

int main() {
    srand(time(NULL));

    playfield_impl field;
    human_player human(1);
    cpu_player cpu(2);

    connect4 game(field, human, cpu);

    game.start();
    return 0;
}
