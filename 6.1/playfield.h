#ifndef PLAYFIELD_H_
#define PLAYFIELD_H_

class playfield {
public:
    // the size of the field
    const static int width=7;
    const static int height=6;
    // the elements stored at individual field positions
    const static int none=0;
    const static int player1=1;
    const static int player2=2;
    // returns the stone (none/player1/player2) at the position
    // 0 <= x <= width
    // 0 <= y <= height
    // stoneat(0,0) ................ top left
    // stoneat(width-1,height-1) ... bottom right
    // if we insert a stone in a new game in column i,
    // it lands at (i,height-1)
    virtual int stoneat(int x, int y) const = 0;
    virtual ~playfield() {}
};

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
    void print();
};

#endif /* PLAYFIELD_H_ */
