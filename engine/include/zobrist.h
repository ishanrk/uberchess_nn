#ifndef UBERCHESS_ZOBRIST_H
#define UBERCHESS_ZOBRIST_H

#include "types.h"
#include "pos.h"

void zobrist_init(void);
U64 zobrist_hash(const Position *pos);

#endif
