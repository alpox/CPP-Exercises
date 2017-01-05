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
    // set_stone returns the y position where the stone was set
    int set_stone(int player, int x);
    bool is_win(int player, int x, int y);
    bool is_win(int player, int x, int y, int dx, int dy);
    static bool is_valid_player(int player);
    static bool is_valid_column(int x);
    static bool is_valid_row(int y);
public:
    playfield_impl();
    playfield_impl(const playfield &field);
    int stoneat(int x, int y) const;
    bool is_full();
    bool can_set_stone(int x);
    bool set_stone_in_column(int player, int x);
    void print();
};

#endif /* PLAYFIELD_H_ */
