#include "movegen.h"

void movegen_pseudo_legal(const Position *pos, MoveList *list) {
    (void)pos;
    list->count = 0;
}

void movegen_legal(const Position *pos, MoveList *list) {
    movegen_pseudo_legal(pos, list);
}
