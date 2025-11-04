#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>


int main(void) {
    char *s = NULL;
    size_t cap = 0;

    char buf[200005];
    if (scanf("%200000s", buf) != 1) {
        return 0;
    }

    s = buf;
    size_t n = strlen(s);

    size_t maxWeight = 26u * n + 5u;
    bool *present = (bool *)calloc(maxWeight, sizeof(bool));
    if (!present) {

        return 1;
    }

    long long runLen = 0;
    int prev = 0;
    for (size_t i = 0; i < n; ++i) {
        int c = s[i];
        if (i > 0 && c == prev) {
            runLen++;
        } else {
            runLen = 1;
        }
        int w = (c - 'a' + 1);
        long long weight = (long long)w * runLen;
        if (weight >= 0 && (size_t)weight < maxWeight) {
            present[weight] = true;
        }
        prev = c;
    }

    int q = 0;
    if (scanf("%d", &q) != 1) {
        free(present);
        return 0;
    }

    for (int i = 0; i < q; ++i) {
        long long x;
        if (scanf("%lld", &x) != 1) {
            break;
        }
        if (x >= 0 && (size_t)x < maxWeight && present[x]) {
            puts("Yes");
        } else {
            puts("No");
        }
    }

    free(present);
    return 0;
}

