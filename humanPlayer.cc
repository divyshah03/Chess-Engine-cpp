#include "humanPlayer.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

HumanPlayer::HumanPlayer(Colour colour) : Player{colour} {}

Move HumanPlayer::getMove(Board *board) const {
    string pos;

    char col1, col2 = '@';
    char row1, row2 = -1;

    // From position
    cin >> col1;
    cin >> row1;

    // To position
    cin >> col2;
    cin >> row2;

    Position from{row1, col1};
    Position to{row2, col2};

    PieceType pt = board->getGrid()[to.getRowVector()][to.getColVector()].getPieceType();
    Move mv{from, to, pt};
    return mv;
}
