#include "makemove.h"

bool make_move(Position *pos, Move m, Undo *undo) {
    (void)pos;
    (void)m;
    if (undo) {
        undo->zobrist = 0;
        undo->pawn_key = 0;
        undo->castling = 0;
        undo->ep_square = SQUARE_NONE;
        undo->halfmove_clock = 0;
        undo->fullmove_number = 0;
    }
    return true;
}

void unmake_move(Position *pos, Move m, const Undo *undo) {
    (void)pos;
    (void)m;
    (void)undo;
}
