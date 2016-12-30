#include "playfield.h"
#include "player.h"

int main() {
    playfield board;

    board.start();

    player<playfield> p1;

    while(board.isPlaying()) {
        int col = p1.play(board);
        board.setStoneInColumn(col);

        char input;
        cin >> input;

        int x = input - 'A';
        if(x < 0 || x > playfield::width - 1) {
            cout << "The column has to be between 'A' and 'G'!" << endl;
            cout << "Column: ";
        }
        board.setStoneInColumn(x);
    }

    return 0;
}