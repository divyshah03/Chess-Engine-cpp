#include "info.h"

Info::Info(Position position, Colour colour, PieceType pieceType) 
     :position{position}, colour{colour}, pieceType{pieceType} {}

Position Info::getPosition() const {
    return position;
}

Colour Info::getColour() const {
    return colour;
}

PieceType Info::getPieceType() const {
    return pieceType;
}
