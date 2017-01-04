#ifndef PLAYER_H_
#define PLAYER_H_

#include "playfield.h"
#include <iostream>
#include <vector>

class player {
public:
    virtual int play(const playfield &field) = 0;
    virtual ~player() {};
};

class numbered_player : public player {
public:
    numbered_player(const int& number);

    virtual int play(const playfield &field) = 0;
    int get_number() const;
    void set_number(const int & number);

    bool operator == (const numbered_player &other);
private:
    int number;
};

class human_player : public numbered_player {
public:
	human_player(const int &number);
    int play(const playfield &field);
};

class cpu_player : public numbered_player {
public:
    cpu_player(const int &number);
    int play(const playfield &field);
protected:
    std::vector<int> get_possible_slots(const playfield &field);
    int find_win_slot(const playfield &field, const int & player_number);
};

#endif /* PLAYER_H_ */
