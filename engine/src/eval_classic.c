#include "eval.h"

I32 eval_classic(const Position *pos) {
    (void)pos;
    return 0;
}

I32 eval_nnue(const Position *pos) {
    (void)pos;
    return 0;
}

I32 eval_position(const Position *pos) {
    (void)pos;
    return eval_classic(pos);
}
