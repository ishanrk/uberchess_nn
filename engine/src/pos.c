#include "pos.h"

void pos_init(Position *pos) {
    if (!pos) {
        return;
    }
    for (int c = 0; c < COLOR_NB; c++) {
        for (int p = 0; p < PIECE_NB; p++) {
            pos->pieces[c][p] = 0;
        }
        pos->occupancy[c] = 0;
    }
    pos->all = 0;
    pos->zobrist = 0;
    pos->pawn_key = 0;
    pos->castling = 0;
    pos->ep_square = SQUARE_NONE;
    pos->side_to_move = COLOR_WHITE;
    pos->halfmove_clock = 0;
    pos->fullmove_number = 1;
}

bool pos_from_fen(Position *pos, const char *fen) {
    (void)fen;
    pos_init(pos);
    return true;
}
