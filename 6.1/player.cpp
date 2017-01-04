
#include "player.h"


numbered_player::numbered_player(const int &number) : number(number) {}

int numbered_player::get_number() const {
	return number;
}

void numbered_player::set_number(const int& number_arg) {
	number = number_arg;
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

    int enemy_number = (get_number() == 1) ? 2 : 1;

    int enemy_win_slot = find_win_slot(field, enemy_number);
    if (enemy_win_slot != -1) return enemy_win_slot;

    int win_slot = find_win_slot(field, get_number());
    if (win_slot != -1) return win_slot;

    std::vector<int> possible_slots = get_possible_slots(field);
    return possible_slots.at(rand() % possible_slots.size());
}

int cpu_player::find_win_slot(const playfield &field, const int &player_number){

    for (int slot : get_possible_slots(field)){
        playfield_impl field_copy(field);
            // found winning slot
        	if(field_copy.setStoneInColumn(player_number, slot)) return slot;
    }

    // no winning slot found
    return -1;
}

std::vector<int> cpu_player::get_possible_slots(const playfield& field){
    std::vector<int> possible_slots;
    playfield_impl field_copy(field);
    for(int x = 0; x < playfield::width; x++) {
        if(field_copy.canSetStone(x)) possible_slots.push_back(x);
    }
    return possible_slots;
}