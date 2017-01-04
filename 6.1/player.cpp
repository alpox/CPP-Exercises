
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
	std::vector<int> free_slots;

    for(int x = 0; x < playfield::width; x++) {

        playfield_impl field_copy(field);

        if(field_copy.canSetStone(x)){

            // Found a winning slot
			if(field_copy.setStoneInColumn(get_number(), x)) return x;

            // Slot is free.
            free_slots.push_back(x);
        }
    }

    // Returns any free slot
    return free_slots.at(rand() % free_slots.size());
}