#include "move.h"

Move move_make(Square from, Square to, U32 flags, U32 promo) {
    return (Move)((U32)from | ((U32)to << 6) | (flags << 12) | (promo << 20));
}

Square move_from(Move m) {
    return (Square)(m & 0x3F);
}

Square move_to(Move m) {
    return (Square)((m >> 6) & 0x3F);
}

U32 move_flags(Move m) {
    return (U32)((m >> 12) & 0xFF);
}

U32 move_promo(Move m) {
    return (U32)((m >> 20) & 0xF);
}
