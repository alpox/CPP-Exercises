
#include "player.h"


numbered_player::numbered_player(const int &number) : number(number) {}

int numbered_player::get_number() const {
	return number;
}

int numbered_player::get_enemy_number() const {
	return (number == 1) ? 2 : 1;
}

bool numbered_player::operator== (const numbered_player &other){
	return number == other.get_number();	
}

human_player::human_player(const int &number) : numbered_player(number) {}

int human_player::play(const playfield &field){
	playfield_impl(field).print();

    char input;

    std::cout << "Choose column (A-"<< (char)('A' + playfield::width - 1) << "): ";

    do {
        std::cin >> input;

        if(input < 'A' || input > 'Z') {
            std::cout << "'" << input << "' is no valid column!" << std::endl;
            std::cout << "Please enter a valid column (A-Z): ";
            continue;
        }

        break;
    } while(true);

    return (int)input - 65;
}

cpu_player::cpu_player(const int &number) : numbered_player(number) {}

int cpu_player::play(const playfield &field){

    int win_slot = find_win_slot(field, get_number());
    if (win_slot != -1) return win_slot;

    int enemy_win_slot = find_win_slot(field, get_enemy_number());
    if (enemy_win_slot != -1) return enemy_win_slot;

    std::vector<int> possible_slots = get_possible_slots(field);
    return possible_slots.at(rand() % possible_slots.size());
}

int cpu_player::find_win_slot(const playfield &field, const int &player_number){

    for (int slot : get_possible_slots(field)){
        playfield_impl field_copy(field);
            // found winning slot
        	if(field_copy.set_stone_in_column(player_number, slot)) return slot;
    }

    // no winning slot found
    return -1;
}

std::vector<int> cpu_player::get_possible_slots(const playfield& field){
    std::vector<int> possible_slots;
    playfield_impl field_copy(field);
    for(int x = 0; x < playfield::width; x++) {
        if(field_copy.can_set_stone(x)) possible_slots.push_back(x);
    }
    return possible_slots;
}

threaded_cpu_player::threaded_cpu_player(const int &number) : cpu_player(number) {}

int threaded_cpu_player::play(const playfield &field){

    playfield_impl actual_field(field);
    int slot;

    // wait until computation finished from last round
    computation_mutex.lock();

    // computation finished
    for(std::pair<playfield_impl, int> future_strategy : future_strategies){
        if (future_strategy.first == actual_field){
            slot = future_strategy.second;
            break;
        }
    }
    computation_mutex.unlock();

    // start next round's computation
    playfield_impl updated_field(field);
    updated_field.set_stone_in_column(get_number(), slot);
    compute_futures(updated_field);

    return slot;
}

void threaded_cpu_player::compute_futures(const playfield_impl &field){

    computation_mutex.lock();
    future_strategies.clear();
    std::vector<int> enemy_possible_slots = get_possible_slots(field);

    // initialize count down latch. the last finishing thread will unlock the lock
    count_down_latch_mutex.lock();
    count_down_latch = enemy_possible_slots.size();
    count_down_latch_mutex.unlock();

    for (int enemy_possible_slot : enemy_possible_slots){
        playfield_impl future_field(field);
        future_field.set_stone_in_column(get_enemy_number(), enemy_possible_slot);
        std::thread future_computation(&threaded_cpu_player::future, this, future_field);
    }
}

// thread
void threaded_cpu_player::future(const playfield_impl &future_field){

    // find winning slot on possible enemy turn
    int win_slot = cpu_player::find_win_slot(future_field, cpu_player::get_number());

    // find enemy winning slot on possible enemy turn
    int enemy_win_slot = cpu_player::find_win_slot(future_field, cpu_player::get_enemy_number());

    // random slot on possible enemy turn
    std::vector<int> possible_slots = cpu_player::get_possible_slots(future_field);
    int random_possible_slot = possible_slots.at(rand() % possible_slots.size());

    // priority order: win_slot, enemy_win_slot, random_possible_slot
    std::pair<playfield_impl, int> future_strategy(future_field, (win_slot != -1) ? win_slot : (enemy_win_slot != -1) ? enemy_win_slot : random_possible_slot);
    future_strategies.push_back(future_strategy);

    // check if this thread is the last thread
    count_down_latch_mutex.lock();
    if ( --count_down_latch == 0 ) {
        computation_mutex.unlock();
    }
    count_down_latch_mutex.unlock();
}