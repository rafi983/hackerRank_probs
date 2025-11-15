#include <stdio.h>
#include <stdlib.h>

long long bricksGame(long long *a, int n) {
    if (n <= 3) {
        long long s = 0;
        for (int i = 0; i < n; i++) s += a[i];
        return s;
    }
    long long *dp = (long long *)calloc(n + 4, sizeof(long long));
    long long *suf = (long long *)malloc((n + 1) * sizeof(long long));
    suf[n] = 0;
    for (int i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] + a[i];
    for (int i = n - 1; i >= 0; i--) {
        long long m1 = dp[i + 1];
        long long m2 = dp[i + 2];
        long long m3 = dp[i + 3];
        long long mn = m1;
        if (m2 < mn) mn = m2;
        if (m3 < mn) mn = m3;
        dp[i] = suf[i] - mn;
    }
    long long ans = dp[0];
    free(dp);
    free(suf);
    return ans;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int n;
        if (scanf("%d", &n) != 1) return 0;
        long long *a = (long long *)malloc(n * sizeof(long long));
        for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
        long long res = bricksGame(a, n);
        printf("%lld\n", res);
    }
    return 0;
}

