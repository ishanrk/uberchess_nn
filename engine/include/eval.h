#ifndef UBERCHESS_EVAL_H
#define UBERCHESS_EVAL_H

#include "pos.h"

I32 eval_classic(const Position *pos);
I32 eval_nnue(const Position *pos);
I32 eval_position(const Position *pos);

#endif
