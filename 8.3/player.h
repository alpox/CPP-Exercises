#ifndef PLAYER_H_
#define PLAYER_H_

#include "playfield.h"
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

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
    int get_enemy_number() const;

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

class threaded_cpu_player : public cpu_player {
public:
    threaded_cpu_player(const int &number);
    int play(const playfield &field);
private:
    std::vector<std::pair<playfield_impl, int> > future_strategies;
    void compute_futures(const playfield_impl &field);
    void future(const playfield_impl &future_field);
    std::mutex computation_mutex;
    std::mutex count_down_latch_mutex;
    int count_down_latch;
};

#endif /* PLAYER_H_ */
