#include <stdio.h>
#include <stdlib.h>

static int compare_int(const void *a, const void *b) {
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    if (*ia < *ib) {
        return -1;
    }
    if (*ia > *ib) {
        return 1;
    }
    return 0;
}

int main(void) {
    int n;
    int k;
    if (scanf("%d %d", &n, &k) != 2 || n <= 0 || k < 0) {
        return 0;
    }

    int *x = malloc(sizeof(int) * n);
    if (!x) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &x[i]) != 1) {
            return 0;
        }
    }

    qsort(x, (size_t)n, sizeof(int), compare_int);

    int transmitters = 0;
    int i = 0;
    while (i < n) {
        transmitters++;

        int loc = x[i] + k;
        while (i < n && x[i] <= loc) {
            i++;
        }
        int tower_pos = x[i - 1];

        loc = tower_pos + k;
        while (i < n && x[i] <= loc) {
            i++;
        }
    }

    printf("%d\n", transmitters);
    return 0;
}

