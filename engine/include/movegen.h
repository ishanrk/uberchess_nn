#ifndef UBERCHESS_MOVEGEN_H
#define UBERCHESS_MOVEGEN_H

#include "move.h"
#include "pos.h"

enum { MOVE_LIST_MAX = 256 };

typedef struct {
    Move moves[MOVE_LIST_MAX];
    U32 count;
} MoveList;

void movegen_pseudo_legal(const Position *pos, MoveList *list);
void movegen_legal(const Position *pos, MoveList *list);

#endif
