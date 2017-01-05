
#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H

#include "player.h"

class player_factory {
public:
	static cpu_player* make_basic_cpu(const int& player_number);
	static human_player* make_human(const int& player_number);
};

#endif