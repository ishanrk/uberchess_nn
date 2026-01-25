#ifndef UBERCHESS_POS_H
#define UBERCHESS_POS_H

#include "types.h"

typedef struct {
    U64 pieces[COLOR_NB][PIECE_NB];
    U64 occupancy[COLOR_NB];
    U64 all;
    U64 zobrist;
    U64 pawn_key;
    U16 castling;
    Square ep_square;
    Color side_to_move;
    U16 halfmove_clock;
    U16 fullmove_number;
} Position;

void pos_init(Position *pos);
bool pos_from_fen(Position *pos, const char *fen);

#endif
