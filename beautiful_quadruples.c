#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c, d;
    if (scanf("%d %d %d %d", &a, &b, &c, &d) != 4) return 0;

    int arr[4] = { a, b, c, d };
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (arr[j] < arr[i]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    int A = arr[0];
    int B = arr[1];
    int C = arr[2];
    int D = arr[3];

    long long *pre = (long long *) malloc((B + 1) * sizeof(long long));
    pre[0] = 0;
    for (int i = 1; i <= B; i++) {
        pre[i] = pre[i - 1] + (i < A ? i : A);
    }

    long long total = 0;
    for (int cc = 1; cc <= C; cc++) {
        int mb = cc < B ? cc : B;
        long long triple = pre[mb];
        total += triple * (D - cc + 1);
    }

    int maxX = 4096;
    long long *cnt = (long long *) calloc(maxX, sizeof(long long));
    long long invalid = 0;

    for (int cc = 1; cc <= C; cc++) {
        if (cc <= B) {
            int limit = cc < A ? cc : A;
            for (int aa = 1; aa <= limit; aa++) {
                cnt[aa ^ cc]++;
            }
        }
        for (int x = 0; x < maxX; x++) {
            int dd = x ^ cc;
            if (dd >= cc && dd <= D) {
                invalid += cnt[x];
            }
        }
    }

    long long result = total - invalid;
    printf("%lld\n", result);


    return 0;
}
