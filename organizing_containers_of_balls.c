#include <stdio.h>
#include <stdlib.h>

static int compare_long_long(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) {
        return -1;
    }
    if (x > y) {
        return 1;
    }
    return 0;
}

int main(void) {
    int q;
    if (scanf("%d", &q) != 1) {
        return 0;
    }

    while (q--) {
        int n;
        if (scanf("%d", &n) != 1) {
            return 0;
        }

        long long *container = calloc((size_t)n, sizeof(long long));
        long long *type = calloc((size_t)n, sizeof(long long));
        if (!container || !type) {
            return 0;
        }

        for (int i = 0; i < n; i++) {
            long long row_sum = 0;
            for (int j = 0; j < n; j++) {
                long long val;
                if (scanf("%lld", &val) != 1) {
                    return 0;
                }
                row_sum += val;
                type[j] += val;
            }
            container[i] = row_sum;
        }

        qsort(container, (size_t)n, sizeof(long long), compare_long_long);
        qsort(type, (size_t)n, sizeof(long long), compare_long_long);

        int possible = 1;
        for (int i = 0; i < n; i++) {
            if (container[i] != type[i]) {
                possible = 0;
                break;
            }
        }

        printf(possible ? "Possible\n" : "Impossible\n");

    }

    return 0;
}

