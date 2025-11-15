#include <stdio.h>
#include <stdlib.h>

static inline int max_int(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n;
    int k;
    if (scanf("%d %d", &n, &k) != 2 || k <= 0 || n <= 0) {
        return 0;
    }

    int *freq = calloc((size_t)k, sizeof(int));
    if (!freq) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int value;
        if (scanf("%d", &value) != 1) {
            return 0;
        }
        int rem = value % k;
        if (rem < 0) {
            rem += k;
        }
        freq[rem]++;
    }

    int result = 0;
    if (freq[0] > 0) {
        result++;
    }

    for (int r = 1; r <= k / 2; r++) {
        if (r == k - r) {
            if (freq[r] > 0) {
                result++;
            }
        } else {
            result += max_int(freq[r], freq[k - r]);
        }
    }

    printf("%d\n", result);

    return 0;
}

