#ifndef PLAYER_H
#define PLAYER_H
#include "move.h"
#include "enumerated.h"
#include "board.h"

class Player {
    Colour colour;

    public:
    Player(Colour colour);
    virtual Move getMove(Board *board) const = 0;
    Colour getColour() const;
};

#endif
