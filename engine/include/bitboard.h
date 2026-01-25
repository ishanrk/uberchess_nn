#ifndef UBERCHESS_BITBOARD_H
#define UBERCHESS_BITBOARD_H

#include "types.h"

U32 bb_popcount(U64 bb);
Square bb_lsb(U64 bb);
U64 bb_pop_lsb(U64 *bb);

#endif
