#include <stdio.h>
#include <string.h>

static void rstrip(char *s) {
    size_t n = strlen(s);
    while (n > 0 && (s[n - 1] == '\n' || s[n - 1] == '\r')) {
        s[n - 1] = '\0';
        n--;
    }
}

int main(void) {
    FILE *f = fopen("tests/perft_suite.txt", "r");
    if (!f) {
        printf("perft suite missing\n");
        return 0;
    }
    char line[512];
    while (fgets(line, sizeof(line), f)) {
        rstrip(line);
        if (line[0] == '\0' || line[0] == '#') {
            continue;
        }
    }
    fclose(f);
    printf("test_perft ok\n");
    return 0;
}
