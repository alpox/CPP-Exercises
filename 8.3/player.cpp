
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

    // find winning slot on possible enemy turn
    int win_slot = find_win_slot(field, get_number());

    // find enemy winning slot on possible enemy turn
    int enemy_win_slot = find_win_slot(field, get_enemy_number());

    // random slot on possible enemy turn
    std::vector<int> possible_slots = get_possible_slots(field);
    int random_possible_slot = possible_slots.at(rand() % possible_slots.size());

    // priority order: win_slot, enemy_win_slot, random_possible_slot
     return (win_slot != -1) ? win_slot : (enemy_win_slot != -1) ? enemy_win_slot : random_possible_slot;
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

threaded_cpu_player::threaded_cpu_player(const int &number) : cpu_player(number), best_responses(initial_best_responses()) {}

threaded_cpu_player::~threaded_cpu_player() {
    // wait for pending threads
    for (std::thread &best_response_computation_thread : best_response_computation_threads){
        best_response_computation_thread.join();
    }
}

int threaded_cpu_player::play(const playfield &field){

    int slot;
    playfield_impl actual_field(field);

    // wait until computation finished from last round
    for (std::thread &best_response_computation_thread : best_response_computation_threads) {
        best_response_computation_thread.join();
    }

    // find which best_response matches the actual field
    best_responses_mutex.lock();
    for(std::pair<playfield_impl, int> &best_response : best_responses){
        if (best_response.first == actual_field) slot = best_response.second;
    }
    best_responses.clear();
    best_responses_mutex.unlock();

    // start next round's computation
    best_response_computation_threads.clear();

    playfield_impl updated_field(field);
    updated_field.set_stone_in_column(get_number(), slot);

    // create every possible enemy move and assign a thread towards calculating the best response
    std::vector<int> enemy_possible_slots = get_possible_slots(updated_field);
    for (int enemy_possible_slot : enemy_possible_slots){
        playfield_impl possible_field(updated_field);
        possible_field.set_stone_in_column(get_enemy_number(), enemy_possible_slot);
        best_response_computation_threads.push_back(std::thread (&threaded_cpu_player::compute_best_response, this, possible_field));
    }

    return slot;
}

// compute best response given enemy's move
void threaded_cpu_player::compute_best_response(const playfield_impl &possible_field){
    // best response
    int slot = cpu_player::play(possible_field);

    // save field and best response
    best_responses_mutex.lock();
    best_responses.push_back(std::pair<playfield_impl, int>(possible_field, slot));
    best_responses_mutex.unlock();
}

// computes initial best responses
std::vector<std::pair<playfield_impl, int> > threaded_cpu_player::initial_best_responses(){

    std::vector<std::pair<playfield_impl, int> > _initial_best_responses;

    // best response when playing first
    _initial_best_responses.push_back(std::pair<playfield_impl, int>(playfield_impl(), playfield::width / 2));

    // best responses when playing second
    for(int x = 0; x < playfield::width; ++x){
        playfield_impl possible_field;
        possible_field.set_stone_in_column(get_enemy_number(), x);
        int slot = (x == playfield::width / 2) ? (playfield::width / 2) -1 : rand() % playfield::width;
        _initial_best_responses.push_back(std::pair<playfield_impl, int>(possible_field, slot));
    }

    return _initial_best_responses;
}