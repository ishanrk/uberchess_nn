#include "nnue.h"

void nnue_init(void) {
}

void nnue_refresh(const Position *pos, NNUEState *state) {
    (void)pos;
    if (state) {
        state->placeholder = 0;
    }
}

I32 nnue_evaluate(const NNUEState *state, const Position *pos) {
    (void)state;
    (void)pos;
    return 0;
}
