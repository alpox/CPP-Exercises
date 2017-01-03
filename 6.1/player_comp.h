#ifndef PLAYER_COMP_H_
#define PLAYER_COMP_H_

#include <iostream>

#include "player.h"
#include "playfield.h"
#include "playfield_impl.h"

class base_strategy {
public:
    int operator()(const playfield &field, const int &player_number);
};

template<typename strategy = base_strategy>
class player_comp : public player {
private:
    int player_number;
public:
    int play(const playfield &field);
    player_comp(const int &player_number);
    ~player_comp();
};


#endif /* PLAYER_H_ */
