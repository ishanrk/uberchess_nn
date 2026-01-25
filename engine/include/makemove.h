#ifndef UBERCHESS_MAKEMOVE_H
#define UBERCHESS_MAKEMOVE_H

#include "move.h"
#include "pos.h"

typedef struct {
    U64 zobrist;
    U64 pawn_key;
    U16 castling;
    Square ep_square;
    U16 halfmove_clock;
    U16 fullmove_number;
} Undo;

bool make_move(Position *pos, Move m, Undo *undo);
void unmake_move(Position *pos, Move m, const Undo *undo);

#endif
