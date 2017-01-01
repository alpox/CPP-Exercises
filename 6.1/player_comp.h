#ifndef PLAYER_COMP_H_
#define PLAYER_COMP_H_

#include <iostream>

#include "player.h"
#include "playfield.h"
#include "playfield_impl.h"

class player_comp : public player {
private:
    playfield_impl *simulationField = NULL;

    int playerNumber;

    void copyFieldToSimulation(const playfield &field);
    void deleteSimulation();
public:
    int play(const playfield &field);
    player_comp(int playerNumber) : playerNumber(playerNumber) { }
    ~player_comp() { deleteSimulation(); }
};

#endif /* PLAYER_H_ */
