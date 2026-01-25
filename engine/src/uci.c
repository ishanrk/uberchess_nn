#include "uci.h"

#include <stdio.h>
#include <string.h>

static void uci_respond_id(void) {
    printf("id name Uberchess_NN\n");
    printf("id author cursor\n");
    printf("uciok\n");
}

void uci_loop(void) {
    char line[256];
    while (fgets(line, sizeof(line), stdin)) {
        if (strncmp(line, "uci", 3) == 0) {
            uci_respond_id();
        } else if (strncmp(line, "isready", 7) == 0) {
            printf("readyok\n");
        } else if (strncmp(line, "quit", 4) == 0) {
            break;
        }
    }
}
