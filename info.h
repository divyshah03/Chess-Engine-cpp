#ifndef INFO_H
#define INFO_H
#include "position.h"
#include "enumerated.h"

class Info {
    Position position;
    Colour colour;
    PieceType pieceType;

    public:
    Info(Position position, Colour colour, PieceType pieceType);
    Position getPosition() const;
    Colour getColour() const;
    PieceType getPieceType() const;
};

#endif
