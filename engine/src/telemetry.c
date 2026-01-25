#include "telemetry.h"

#include <stdio.h>

void telemetry_reset(Telemetry *t) {
    if (!t) {
        return;
    }
    t->depth = 0;
    t->seldepth = 0;
    t->nodes = 0;
    t->nps = 0;
    t->tthit_permille = 0;
    t->pv_len = 0;
    t->root_len = 0;
}

void telemetry_set_depth(Telemetry *t, U32 depth, U32 seldepth) {
    t->depth = depth;
    t->seldepth = seldepth;
}

void telemetry_set_nodes(Telemetry *t, U64 nodes, U64 nps) {
    t->nodes = nodes;
    t->nps = nps;
}

void telemetry_set_tt_hit(Telemetry *t, U32 permille) {
    t->tthit_permille = permille;
}

void telemetry_set_pv(Telemetry *t, const Move *moves, U32 len) {
    if (!t) {
        return;
    }
    if (len > TELEMETRY_PV_MAX) {
        len = TELEMETRY_PV_MAX;
    }
    for (U32 i = 0; i < len; i++) {
        t->pv[i] = moves[i];
    }
    t->pv_len = len;
}

void telemetry_set_root_stats(Telemetry *t, const RootMoveStat *stats, U32 len) {
    if (!t) {
        return;
    }
    if (len > TELEMETRY_ROOT_MAX) {
        len = TELEMETRY_ROOT_MAX;
    }
    for (U32 i = 0; i < len; i++) {
        t->root[i] = stats[i];
    }
    t->root_len = len;
}

void telemetry_emit_root(const Telemetry *t) {
    if (!t) {
        return;
    }
    printf("info depth %u seldepth %u nodes %llu nps %llu tthitpermille %u\n",
           t->depth,
           t->seldepth,
           (unsigned long long)t->nodes,
           (unsigned long long)t->nps,
           t->tthit_permille);
}
