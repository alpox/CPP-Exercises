
#include "player_comp.h"

#include <stdlib.h>
#include <time.h>
#include <vector>
#include <cassert>

int randomInteger(int max) {
    return rand() % max;
}

int player_comp::play(const playfield &field) {
    copyFieldToSimulation(field);

    assert(!simulationField->isFull());

    std::vector<int> free;
    for(int x = 0; x < playfield::width; x++) {
        playfield_impl impCopy(*simulationField);
        if(!impCopy.canSetStone(x)) continue;
        if(impCopy.setStoneInColumn(playerNumber, x)) return x;

        // Slot is free. remember.
        free.push_back(x);
    }
    return free.at(randomInteger(free.size()));
}

void player_comp::deleteSimulation() {
    if(simulationField != NULL) delete simulationField;
}

void player_comp::copyFieldToSimulation(const playfield &field) {
    deleteSimulation();
    simulationField = new playfield_impl();


    for(int x = 0; x < playfield::width; x++) {
        for(int y = playfield::height - 1; y >= 0; y--) {
            if(field.stoneat(x, y) == playfield::none) continue;
            simulationField->setStoneInColumn(field.stoneat(x, y), x);
        }
    }
}
