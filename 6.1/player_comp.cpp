
#include "player_comp.h"

#include <stdlib.h>
#include <time.h>
#include <vector>
#include <cassert>

player_comp::player_comp(const int &player_number) : player_number(player_number) {}

player_comp::~player_comp() {}

int player_comp::play(const playfield &field) {
    std::vector<int> free_slots;

    for(int x = 0; x < playfield::width; x++) {
        
        playfield_impl field_copy(field);

        if(field_copy.canSetStone(x)){

            // Found a winning slot
            if(field_copy.setStoneInColumn(player_number, x)) return x;

            // Slot is free.
            free_slots.push_back(x);
        }
    }

    // Returns any free slot
    return free_slots.at(rand() % free_slots.size());
}
