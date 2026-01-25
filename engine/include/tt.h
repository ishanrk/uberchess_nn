#ifndef UBERCHESS_TT_H
#define UBERCHESS_TT_H

#include "types.h"
#include "move.h"

typedef struct {
    U64 key;
    Move move;
    I32 score;
    U16 depth;
    U16 flags;
} TTEntry;

typedef struct {
    TTEntry *entries;
    U64 mask;
} TTTable;

void tt_init(TTTable *tt, U64 mb);
void tt_free(TTTable *tt);
bool tt_probe(const TTTable *tt, U64 key, TTEntry *out);
void tt_store(TTTable *tt, U64 key, const TTEntry *entry);

#endif
