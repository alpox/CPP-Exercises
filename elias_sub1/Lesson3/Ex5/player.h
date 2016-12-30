//
// Created by Elias on 12.10.16.
//

#ifndef EX5_PLAYER_H
#define EX5_PLAYER_H

#include "playfield.h"

template<typename F>
class player {
private:
    int checkColumnForWin(const F &field, int x) {
        bool win;
        for(int y = playfield::height - 1; y >= 0; y--) {
            if(field.stoneat(x,y) != playfield::none) continue;

            // Check to right
            win = isPlayerWin(field, x, y, 1, 0);
            // Check to left
            if(!win)
                win = isPlayerWin(field, x, y, -1, 0);
            // Check to bottom
            if(!win)
                win = isPlayerWin(field, x, y, 0, 1);
            // Check diag right
            if(!win)
                win = isPlayerWin(field, x, y, 1, 1);
            // Check diag left
            if(!win)
                win = isPlayerWin(field, x, y, -1, 1);
            // Check diag top left
            if(!win)
                win = isPlayerWin(field, x, y, -1, -1);
            // Check diag top right
            if(!win)
                win = isPlayerWin(field, x, y, 1, -1);
            // No more checks needed here - all cases are catched
            break;
        }
        return win;
    }
    bool shouldCheck(int x, int y, int dirX, int dirY) {
        bool shortLeft = x < 3;
        bool shortRight = x > playfield::width - 4;
        bool shortTop = y < 3;
        bool shortBottom = y > playfield::height - 4;

        // Trying to left not possible
        if(shortLeft && dirX == -1) return false;
        // Trying to right not possible
        if(shortRight && dirX == 1) return false;
        // Trying to top not possible
        if(shortTop && dirY == -1) return false;
        // Trying to bottom not possible
        if(shortBottom && dirY == 1) return false;

        // Can check otherwise
        return true;
    }
    bool isPlayerWin(const F &field, int x, int y, int dirX, int dirY) {
        bool isWin = true; // Initialize with first player

        // Should we even check this direction?
        if(!shouldCheck(x, y, dirX, dirY)) return 0; // No win here
        for(int i = 1; i < 4; i++) {
            // If the i-th iteration doesn't match with the initial
            // player value, return 0 (no win)
            if(field.stoneat(x + dirX * i, y + dirY * i) != field.currentPlayer()) return 0;
        }
        return isWin;
    }
    int canSetInColumn(const F &field, int col) {
        if(field.stoneat(col, 0) == playfield::none) return true;
        return false;
    }
public:
    // returns the column where the player decides to throw in his
    // stone
    // F is the playfield which may be any playfield implementing
    // the stoneat method, if you expect a different class because
    // you need methods to verify whether the opponent can win,
    // copy the field into the class that you expect.
    int play(const F &field) {
        int firstFree = -1;
        for(int i = 0; i < playfield::width; i++) {
            if(!canSetInColumn(field, i)) continue;
            if(firstFree == -1) firstFree = i;
            if(checkColumnForWin(field, i)) return i;
        }
        return firstFree;
    }
};

#endif //EX5_PLAYER_H
