#include "graphicsDisplay.h"
#include "position.h"
#include "enumerated.h"
#include <string>

using namespace std;

const int DEFAULT_WINDOW_SIZE = 500;

GraphicsDisplay::GraphicsDisplay(size_t n) {
    cellSize = DEFAULT_WINDOW_SIZE / GRID_SIZE;
    Colour c1 = Colour::LIGHTBROWN;
    Colour c2 = Colour::DARKBROWN;
    
    // drawing the background
    for (int row = 0; row < GRID_SIZE; ++row) {
        for (int col = 0; col < GRID_SIZE; ++col) {
            Colour curColour = ((row + col) % 2 == 0) ? c2 : c1;
            xw.fillRectangle(col * cellSize, (GRID_SIZE - 1 - row) * cellSize, cellSize, cellSize, curColour);
        }
    }

}

void GraphicsDisplay::drawCell(const Info& info){
    Position position = info.getPosition();
    Colour colour = info.getColour();
    PieceType pieceType = info.getPieceType();

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
            symbol = ' ';
            break;
    }

    std::string symbolStr(1, symbol);
    int col = position.getColVector();
    int row = position.getRowVector();

    int cellX = col * cellSize;
    int cellY = (7 - row) * cellSize;

    // Redraw the cell background before drawing the piece
    Colour backgroundColour = ((row + col) % 2 == 0) ? Colour::DARKBROWN : Colour::LIGHTBROWN;
    xw.fillRectangle(cellX, cellY, cellSize, cellSize, backgroundColour);

    // Font metrics
    XFontStruct *fontStruct = xw.getFontStruct();
    int textWidth = XTextWidth(fontStruct, symbolStr.c_str(), symbolStr.length());
    int textHeight = fontStruct->ascent + fontStruct->descent;

    // Center text in the cell
    int x = cellX + (cellSize - textWidth) / 2;
    int y = cellY + (cellSize + textHeight) / 2 - fontStruct->descent;

    xw.drawString(x, y, symbolStr, colour);
}

void GraphicsDisplay::notify(Subject& whoNotified){
    Info info = whoNotified.getInfo();
    drawCell(info);
}
