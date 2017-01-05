#ifndef PLAYER_H_
#define PLAYER_H_

#include "playfield.h"
#include <iostream>
#include <vector>
#include <thread>

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
    ~threaded_cpu_player();
    int play(const playfield &field);
private:

    // vector containing pairs of possible_fields and their best responses
    std::vector<std::pair<playfield_impl, int> > best_responses;
    
    // mutex lock for best_responses
    std::mutex best_responses_mutex;

    // vector containing threads which compute the best response given a possible_field
    std::vector<std::thread> best_response_computation_threads;

    // the computation of a best response given a possible_field. To be executed by a thread
    void compute_best_response(const playfield_impl &pussible_field);

    // calculates all initial best responses. That is all best reponses on the beggining of a game
    std::vector<std::pair<playfield_impl, int> > initial_best_responses();
};

#endif /* PLAYER_H_ */
