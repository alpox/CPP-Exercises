
#include "player_factory.h"

cpu_player* player_factory::make_basic_cpu(const int &player_number){
	cpu_player* player = new cpu_player(player_number);
	return player;
}

human_player* player_factory::make_human(const int &player_number){
	human_player* player = new human_player(player_number);
	return player;
}