#ifndef ENUMERATED_H
#define ENUMERATED_H

#include <iostream>

enum class Colour{
    WHITE,
    BLACK,
    NONE,
    GREY,
    GREEN,
    LIGHTBROWN,
    DARKBROWN,
    PINK,
    RED,
    BLUE,
    ORANGE
};

enum class PieceType{
    KING,
    QUEEN,
    BISHOP,
    ROOK,
    KNIGHT,
    PAWN,
    NONE
};

// Output operator for PieceType
std::ostream& operator<<(std::ostream &out, PieceType pt);

#endif
