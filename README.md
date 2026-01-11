# Chess Game

A terminal and graphics based two-player chess game written in modern C++20. Includes support for human vs. human play, human vs computer play, customizable board setup, basic AI using a stockfish chess engine, and optional enhancements such as a countdown timer for competitive play and undo moves.

---

## 🔧 Features

- Fully functional chess engine with move validation
- Text-based UI with graphical display (via X11)
- Supports standard chess rules: check, checkmate, stalemate, en passant, castling, and promotion
- Command-line setup mode for custom board configuration
- Timer feature with Blitz, Rapid, and Classical modes
- Human vs Human and Human vs Computer modes
- Uses Smart Pointers everywhere possible

---

## 🖥️ How to Build

### Requirements

- g++-14 or later with C++20 support
- X11 libraries 
- Linux/macOS or WSL (Windows Subsystem for Linux)

### Build

- make for compiling the entire game
- make clean for cleaning up the compiled files

---

### ♟️ Supported Chess Mechanics

Our chess engine fully implements the rules of standard chess, including:

- ⛳️ **Check and Checkmate Detection**  
  The game automatically checks for check and checkmate and prevents illegal moves that would leave a king in check.

- ⛳️ **Stalemate Handling**  
  If a player has no legal moves but is not in check, the game correctly declares a stalemate (draw).

- ⛳️ **Castling**  
  Both kingside and queenside castling are supported, provided all rules are satisfied:
  - Neither the king nor the rook involved has moved.
  - The squares between them are empty.
  - The king is not in check, and does not pass through or land on a square under attack.

- ⛳️ **En Passant**  
  En passant captures are supported immediately after a pawn moves two squares forward from its starting rank and lands beside an enemy pawn.

- ⛳️ **Pawn Promotion**  
  When a pawn reaches the opposite end of the board, it can be promoted to a queen, rook, bishop, or knight.

### 🕹️ Gameplay Commands

- `game white human black human` — Start a game between two human players  
- `game white human black computer[1-4]` — Start a game against AI of level 1–4  
- `move e2 e4` — Move a piece from e2 to e4  
- `resign` — Resign the game  
- `setup` — Enter setup mode to customize the board  
- `help` - Gives the player help on the commands available

### 🔧 Setup Mode Commands

- `+ K e1` — Add a white king to square e1  
- `- d7` — Remove a piece from square d7  
- `= white` — Set the current turn to white  
- `= black` — Set the current turn to black  
- `done` — Exit setup mode and start the game  

## 🚩 Optional Enhancements

- `-bonus` — Enables timer and undo move features  
Run the game with:
./chess -enablebonus

## 🧑‍💻 Authors

This project was built by Divy, Kshaman and Siddh as part of the CS246 Chess Project at the University of Waterloo.
