#ifndef CELL_H
#define CELL_H
#include "position.h"
#include "piece.h"
#include "move.h"
#include "info.h"
#include "subject.h"
#include "observer.h"
#include "state.h"

class Cell : public Subject, public Observer {
    Position position;
    Piece occupant;
    std::vector <Move> allValidMoves;
    Direction reverseDirection(Direction dir); // helper function for notify

    void NoneResponse(State fromState, Direction calculatedDir);
    void KingResponse(State fromState, Direction calculatedDir);
    void QueenResponse(State fromState, Direction calculatedDir);
    void BishopResponse(State fromState, Direction calculatedDir);
    void KnightResponse(State fromState, Direction calculatedDir);
    void RookResponse(State fromState, Direction calculatedDir);
    void PawnResponse(State fromState, Direction calculatedDir);

    Direction calcDirection(Position pos1, Position pos2);

    bool Attackable(PieceType pieceType, Direction dir, Colour colour = Colour::NONE);
    bool moveAblePawn(Colour colour, Direction dir);
    
    public:
    void Reset(); // helper function
    bool isProtected = false;
    Cell(); // default constructor
    Cell(Position position, Piece occupant);
    Position getPosition();
    Piece getPiece() const;
    void setPiece(Piece piece);
    std::vector <Move> getAllValidMoves();
    bool isOccupied();
    Info getInfo() const override;
    void notify(Subject &from) override;
    PieceType getPieceType() const;
    void setCell(Info info, State state);
};

#endif
