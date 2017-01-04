
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
    assert(isValidColumn(x));
    assert(isValidRow(y));

    return rep[x][y]; 
}

bool playfield_impl::canSetStone(int x) {
    assert(isValidColumn(x));

    return !stoneat(x, 0);
}

bool playfield_impl::isValidPlayer(int player) {
    return player == none 
        || player == player1
        || player == player2;
}

bool playfield_impl::isValidColumn(int x) {
    return x >= 0 && x < playfield::width;
}

bool playfield_impl::isValidRow(int y) {
    return y >= 0 && y < playfield::height;
}

int playfield_impl::setStone(int player, int x) {
    assert(isValidColumn(x));
    assert(isValidPlayer(player));
    assert(canSetStone(x));

    int i = playfield::height - 1;
    while(stoneat(x, i) != 0) i--;
    rep[x][i] = player;
    return i;
}

bool playfield_impl::isWin(int player, int x, int y, int dx, int dy) {
    assert(isValidPlayer(player));

    if(!isValidColumn(x)) return false;
    if(!isValidRow(y)) return false;

    int same = 0;
    bool inverted = false;

    for(int i = 0; i < 4; i++) {
        int xx = inverted ? x - (i * dx) : x + (i * dx);
        int yy = inverted ? y - (i * dy) : y + (i * dy);

        bool found = isValidColumn(xx) && isValidRow(yy) && stoneat(xx, yy) == player;

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

bool playfield_impl::isWin(int player, int x, int y) {
    assert(isValidPlayer(player));
    assert(isValidColumn(x));
    assert(isValidRow(y));

    bool win = false;

    win = win || isWin(player, x, y,  1, 0);
    win = win || isWin(player, x, y,  0, 1);
    win = win || isWin(player, x, y,  1, 1);
    win = win || isWin(player, x, y, -1, 1);

    return win;
}

bool playfield_impl::isFull() {
    for(int x = 0; x < playfield::width; x++)
        if(canSetStone(x)) return false;
    return true;
}

bool playfield_impl::setStoneInColumn(int player, int x) {
    if(!isValidColumn(x)) {
        std::cout << "Given column is not valid!" << std::endl;
        return false;
    }
    if(!isValidPlayer(player)) {
        std::cout << "Given player is no valid player!" << std::endl;
        return false;
    }
    if(!canSetStone(x)) {
        std::cout << "Cannot set stone in column " << x << ". Column is full." << std::endl;
        return false;
    }

    int y = setStone(player, x);
    return isWin(player, x, y);
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