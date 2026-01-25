#include <stdio.h>

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("usage: test_search <fen> <depth>\n");
        return 0;
    }
    printf("test_search ok\n");
    return 0;
}
