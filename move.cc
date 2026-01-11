#include "move.h"

// Default constructor - creates invalid move
Move::Move()
    : from{Position{-1,'@'}}, to{Position{-1,'@'}}, pieceCaptured{PieceType::NONE} {}

Move::Move(Position from, Position to, PieceType pieceCaptured)
     : from{from}, to{to}, pieceCaptured{pieceCaptured} {}

Position Move::getFrom() const {
    return from;
}

Position Move::getTo() const {
    return to;
}

PieceType Move::getPieceType() {
    return pieceCaptured;
}

bool Move::isCaptured() {
    return (pieceCaptured != PieceType::NONE);
}

bool Move::operator==(const Move& other) const{
   return (from == other.from && to == other.to && pieceCaptured == other.pieceCaptured);
}
