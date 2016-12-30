#include "playfield.h"

int main() {
    playfield<istream, istream> board(cin, cin);

    board.start();
    return 0;
}