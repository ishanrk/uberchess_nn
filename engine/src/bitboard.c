#include "bitboard.h"

U32 bb_popcount(U64 bb) {
    U32 count = 0;
    while (bb) {
        bb &= bb - 1;
        count++;
    }
    return count;
}

Square bb_lsb(U64 bb) {
    if (bb == 0) {
        return SQUARE_NONE;
    }
    U32 idx = 0;
    while ((bb & 1ULL) == 0) {
        bb >>= 1;
        idx++;
    }
    return (Square)idx;
}

U64 bb_pop_lsb(U64 *bb) {
    if (*bb == 0) {
        return 0;
    }
    U64 lsb = *bb & (~*bb + 1);
    *bb &= *bb - 1;
    return lsb;
}
