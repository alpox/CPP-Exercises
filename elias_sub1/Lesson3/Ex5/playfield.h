//
// Created by Elias on 11.10.16.
//

#ifndef EX5_PLAYERFIELD_H
#define EX5_PLAYERFIELD_H

#include <iostream>

using namespace std;

class playfield { public:

    // the size of the field
    const static int width=7;
    const static int height=6;

    // these elements are used to indicate whether a given position
    // in the playing field is taken by a given player
    const static int none=0;
    const static int player1=1;
    const static int player2=2;

    bool playing;

    int actualPlayer;
protected:
    // the internal representation of the field
    char rep[playfield::width][playfield::height];
private:
    // returns the player which won or 0 if no player won
    int checkFieldForWin() {
        for(int y = 0; y < playfield::height; y++) {
            for(int x = 0; x < playfield::width; x++) {
                int win = none;
                // Check to right
                win = isPlayerWin(x, y, 1, 0);
                if(win != none) return win;
                // Check to bottom
                win = isPlayerWin(x, y, 0, 1);
                if(win != none) return win;
                // Check diag right
                win = isPlayerWin(x, y, 1, 1);
                if(win != none) return win;
                // Check diag left
                win = isPlayerWin(x, y, -1, 1);
                if(win != none) return win;

                // No more checks needed here - all cases are catched
            }
        }
        return none;
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

    int isPlayerWin(int x, int y, int dirX, int dirY) {
        int isWin = stoneat(x,y); // Initialize with first player
        if(isWin == none) return none; // No player here, so no win already.

        // Should we even check this direction?
        if(!shouldCheck(x, y, dirX, dirY)) return none; // No win here
        for(int i = 1; i < 4; i++) {
            // If the i-th iteration doesn't match with the initial
            // player value, return 0 (no win)
            if(stoneat(x + dirX * i, y + dirY * i) != isWin) return none;
        }
        return isWin;
    }

    bool handleWinIfWin() {
        int winningPlayer = 0;
        if(!(winningPlayer = checkFieldForWin())) {
            if(isFull()) {
                playing = false;
                cout << "The field is full. Its a pair.";
            }
            return false;
        }
        cout << "Player " <<  winningPlayer << " won!";
        playing = false;
        return true;
    }

    void printField() {
        cout << endl;
        for(int p = 0; p < playfield::width; p++) {
            cout << "-----";
        }
        cout << endl;
        for(int y = 0; y < playfield::height; y++) {
            for(int x = 0; x < playfield::width; x++) {
                int sp = stoneat(x, y);
                char ch;
                switch(sp) {
                    case player1:
                        ch = 'X';
                        break;
                    case player2:
                        ch = 'O';
                        break;
                    default:
                        ch = ' ';
                        break;
                }
                cout << "|" << " " << ch << " " << "|";
            }
            cout << endl;
        }

        for(int p = 0; p < playfield::width; p++) {
            cout << "-----";
        }
        cout << endl;
        for(int p = 0; p < playfield::width; p++) {
            cout << "  " << (char)('A' + p) << "  ";
        }
        cout << endl;
    }

    void clear() {
        for(int y = 0; y < playfield::height; y++) {
            for(int x = 0; x < playfield::width; x++) {
                rep[x][y] = none;
            }
        }
    }

    bool setStone(int player, int x) {
        int i = playfield::height - 1;
        while(stoneat(x, i) != 0) i--;
        if(i == -1) return false;
        rep[x][i] = player;
        return true;
    }
public:

    bool setStoneInColumn(int x) {
        if(!playing) {
            cout << "No game is going on.";
            return false;
        }
        if(!isFull()) {
            bool hasSetStone;

            hasSetStone = setStone(actualPlayer, x);

            printField();
            if(handleWinIfWin()) return false;

            if(hasSetStone) {
                if (actualPlayer == player1) actualPlayer = player2;
                else actualPlayer = player1;
            }

            cout << "Column: ";
            return true;
        }
        else {
            handleWinIfWin();
            return false;
        }
    }

    bool isPlaying() const {
        return playing;
    }

    int currentPlayer() const {
        if(!isPlaying()) return none;
        return actualPlayer;
    }

    bool isFull() {
        for(int y = 0; y < playfield::height; y++) {
            for(int x = 0; x < playfield::width; x++) {
                if(stoneat(x, y) == none) return false;
            }
        }
        return true;
    }

    void start() {
        clear();
        printField();

        actualPlayer = player1;

        cout << "Column: ";

        playing = true;
    }


    // return the stone (none/player1/player2) at the position(x,y)
    // 0 <= x <= width
    // 0 <= y <= height
    // stoneat(0,0) ................ top left
    // stoneat(width-1,height-1) ... bottom right
    // if we insert a stone in a new game in column i, // it lands at (i,height-1)
    // implementation may be changed, interface not
    int stoneat(int x, int y) const { return rep[x][y]; }
};

#endif //EX5_PLAYERFIELD_H
