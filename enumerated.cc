#include "enumerated.h"
#include <iostream>

using namespace std;

std::ostream& operator<<(std::ostream &out, PieceType pt){
    switch(pt){
        case PieceType::KING:   return out << "King";
        case PieceType::QUEEN:  return out << "Queen";
        case PieceType::BISHOP: return out << "Bishop";
        case PieceType::ROOK:   return out << "Rook";
        case PieceType::KNIGHT: return out << "Knight";
        case PieceType::PAWN:   return out << "Pawn";
        case PieceType::NONE:   return out << "None";
        default:                return out << "Should not reach this case";
    }
}
