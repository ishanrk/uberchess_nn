#ifndef UBERCHESS_TELEMETRY_H
#define UBERCHESS_TELEMETRY_H

#include "types.h"
#include "move.h"

enum { TELEMETRY_PV_MAX = 128, TELEMETRY_ROOT_MAX = 16 };

typedef struct {
    Move move;
    I32 score;
    U64 nodes;
} RootMoveStat;

typedef struct {
    U32 depth;
    U32 seldepth;
    U64 nodes;
    U64 nps;
    U32 tthit_permille;
    Move pv[TELEMETRY_PV_MAX];
    U32 pv_len;
    RootMoveStat root[TELEMETRY_ROOT_MAX];
    U32 root_len;
} Telemetry;

void telemetry_reset(Telemetry *t);
void telemetry_set_depth(Telemetry *t, U32 depth, U32 seldepth);
void telemetry_set_nodes(Telemetry *t, U64 nodes, U64 nps);
void telemetry_set_tt_hit(Telemetry *t, U32 permille);
void telemetry_set_pv(Telemetry *t, const Move *moves, U32 len);
void telemetry_set_root_stats(Telemetry *t, const RootMoveStat *stats, U32 len);
void telemetry_emit_root(const Telemetry *t);

#endif
