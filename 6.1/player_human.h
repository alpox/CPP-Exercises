#ifndef PLAYER_HUMAN_H_
#define PLAYER_HUMAN_H_

#include <iostream>

#include "player.h"
#include "playfield.h"
#include "playfield_impl.h"

class player_human : public player {
private:
    void printField(const playfield &field);
public:
    int play(const playfield &field);
    ~player_human() {}
};

#endif /* PLAYER_H_ */
