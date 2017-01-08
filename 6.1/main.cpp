
#include "connect4.h"
#include "playfield.h"
#include "player.h"

int main() {
    srand(time(NULL));

    playfield_impl field;
    human_player human(1);
    foreign::player<playfield_impl> cpu_player(2);
    template_player<foreign::player<playfield_impl>> cpu(cpu_player);

    connect4 game(field, &human, &cpu);

    game.start();
    return 0;
}
