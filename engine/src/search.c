#include "search.h"
#include "telemetry.h"

SearchResult search_position(Position *pos, TTTable *tt, U32 depth) {
    (void)pos;
    (void)tt;
    SearchResult result;
    result.score = 0;
    result.best_move = 0;
    result.depth = depth;
    result.seldepth = depth;
    result.nodes = 0;
    return result;
}

I32 search_qsearch(Position *pos, I32 alpha, I32 beta, U32 depth) {
    (void)pos;
    (void)alpha;
    (void)beta;
    (void)depth;
    return 0;
}

I32 search_see(const Position *pos, Move m) {
    (void)pos;
    (void)m;
    return 0;
}
