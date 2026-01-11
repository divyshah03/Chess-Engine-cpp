#include "textDisplay.h"
#include "subject.h"
#include <iostream>

using namespace std;

// Constructor: Initializes an n+1 x n+1 display with '-' in every cell
TextDisplay::TextDisplay(size_t n)
    : gridSize{n} {
    theDisplay.resize(n, vector<char>(n, '-'));
}

// Updates the display when a Cell notifies this observer
void TextDisplay::notify(Subject &whoNotified){
    Info info = whoNotified.getInfo();
    Position position = info.getPosition();
    PieceType pieceType = info.getPieceType();
    Colour colour = info.getColour();

    char symbol;
    switch(pieceType){
        case PieceType::KING :
            symbol = 'K';
            break;
        case PieceType::QUEEN :
            symbol = 'Q';
            break;
        case PieceType::BISHOP :
            symbol = 'B';
            break;
        case PieceType::ROOK :
            symbol = 'R';
            break;
        case PieceType::KNIGHT :
            symbol = 'N';
            break;
        case PieceType::PAWN :
            symbol = 'P';
            break;
        case PieceType::NONE :
            if ((position.getRow() + position.getColVector()) % 2 == 0)
                symbol = ' ';
            else
                symbol = '_';
            break;
    }

    if(colour != Colour::NONE){
        symbol = colour == Colour::BLACK ? symbol + ('a' - 'A') : symbol;
    }

    theDisplay[position.getRowVector()][position.getColVector()] = symbol;
}

// Outputs the board row by row
ostream &operator<<(ostream &out, const TextDisplay &td){
    for(int row = td.gridSize - 1; row >= 0; --row){
        out << row + 1 << " ";
        for(size_t column = 0; column < td.gridSize; ++column){
            out << td.theDisplay[row][column] << " ";
        }
        out << endl;
    }
    out << "\n  a b c d e f g h\n" << endl;
    return out;
}
