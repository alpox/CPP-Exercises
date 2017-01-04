#ifndef PLAYFIELD_IMPL_H_
#define PLAYFIELD_IMPL_H_

#include "playfield.h"

#include <algorithm>

class playfield_impl : public playfield {
protected:
    char rep[playfield::width][playfield::height] = {0};
    // SetStone returns the y position where the stone was set
    int setStone(int player, int x);
    bool isWin(int player, int x, int y);
    bool isWin(int player, int x, int y, int dx, int dy);
    static bool isValidPlayer(int player);
    static bool isValidColumn(int x);
    static bool isValidRow(int y);
public:
    playfield_impl();
    playfield_impl(const playfield &field);
    int stoneat(int x, int y) const;
    bool isFull();
    bool canSetStone(int x);
    bool setStoneInColumn(int player, int x);
};

#endif /* PLAYFIELD_H_ */
