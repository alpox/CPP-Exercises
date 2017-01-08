
#include "playfield.h"

#include <iostream>
#include <cassert>

playfield_impl::playfield_impl() : playfield() {}

playfield_impl::playfield_impl(const playfield &field) {
    for(int x = 0; x < playfield::width; ++x){
        for(int y = 0; y < playfield::height; ++y){
            rep[x][y] = field.stoneat(x,y);
        }
    }
}

int playfield_impl::stoneat(int x, int y) const { 
    assert(is_valid_column(x));
    assert(is_valid_row(y));

    return rep[x][y]; 
}

bool playfield_impl::can_set_stone(int x) {
    assert(is_valid_column(x));

    return !stoneat(x, 0);
}

bool playfield_impl::is_valid_player(int player) {
    return player == none 
        || player == player1
        || player == player2;
}

bool playfield_impl::is_valid_column(int x) {
    return x >= 0 && x < playfield::width;
}

bool playfield_impl::is_valid_row(int y) {
    return y >= 0 && y < playfield::height;
}

int playfield_impl::set_stone(int player, int x) {
    assert(is_valid_column(x));
    assert(is_valid_player(player));
    assert(can_set_stone(x));

    int i = playfield::height - 1;
    while(stoneat(x, i) != 0) i--;
    rep[x][i] = player;
    return i;
}

bool playfield_impl::is_win(int player, int x, int y, int dx, int dy) {
    assert(is_valid_player(player));

    if(!is_valid_column(x)) return false;
    if(!is_valid_row(y)) return false;

    int same = 0;
    bool inverted = false;

    for(int i = 0; i < 4; i++) {
        int xx = inverted ? x - (i * dx) : x + (i * dx);
        int yy = inverted ? y - (i * dy) : y + (i * dy);

        bool found = is_valid_column(xx) && is_valid_row(yy) && stoneat(xx, yy) == player;

        if(found)
            if(++same == 4) return true;

        if(!inverted && (i == 3 || !found)) {
            i = 0;
            inverted = true;
            continue;
        }

        if(!found) break;
    }

    return same >= 4;
}

bool playfield_impl::is_win(int player, int x, int y) {
    assert(is_valid_player(player));
    assert(is_valid_column(x));
    assert(is_valid_row(y));

    bool win = false;

    win = win || is_win(player, x, y,  1, 0);
    win = win || is_win(player, x, y,  0, 1);
    win = win || is_win(player, x, y,  1, 1);
    win = win || is_win(player, x, y, -1, 1);

    return win;
}

bool playfield_impl::is_full() {
    for(int x = 0; x < playfield::width; x++)
        if(can_set_stone(x)) return false;
    return true;
}

int playfield_impl::set_stone_in_column(int player, int x) {
    if(!is_valid_column(x)) {
        std::cout << "Given column is not valid!" << std::endl;
        return -1;
    }
    if(!is_valid_player(player)) {
        std::cout << "Given player is no valid player!" << std::endl;
        return -1;
    }
    if(!can_set_stone(x)) {
        std::cout << "Cannot set stone in column " << x << ". Column is full." << std::endl;
        return -1;
    }

    int y = set_stone(player, x);
    return y;
}

void playfield_impl::print(){
    std::cout << std::endl;
    for(int p = 0; p < playfield::width; p++) {
        std::cout << "-----";
    }
    std::cout << std::endl;
    for(int y = 0; y < playfield::height; y++) {
        for(int x = 0; x < playfield::width; x++) {
            int sp = stoneat(x, y);
            char ch;
            switch(sp) {
                case playfield::player1:
                    ch = 'X';
                    break;
                case playfield::player2:
                    ch = 'O';
                    break;
                default:
                    ch = ' ';
                    break;
            }
            std::cout << "|" << " " << ch << " " << "|";
        }
        std::cout << std::endl;
    }

    for(int p = 0; p < playfield::width; p++) {
        std::cout << "-----";
    }
    std::cout << std::endl;
    for(int p = 0; p < playfield::width; p++) {
        std::cout << "  " << (char)('A' + p) << "  ";
    }
    std::cout << std::endl;
}