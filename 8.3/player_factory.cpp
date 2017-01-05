
#include "player_factory.h"

threaded_cpu_player* player_factory::make_threaded_cpu(const int &player_number){
	threaded_cpu_player* player = new threaded_cpu_player(player_number);
	return player;
}

cpu_player* player_factory::make_basic_cpu(const int &player_number){
	cpu_player* player = new cpu_player(player_number);
	return player;
}

human_player* player_factory::make_human(const int &player_number){
	human_player* player = new human_player(player_number);
	return player;
}
