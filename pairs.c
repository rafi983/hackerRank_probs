#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;
    long long k;
    if (scanf("%d %lld", &n, &k) != 2) return 0;
    long long *a = (long long *)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    qsort(a, n, sizeof(long long), cmp);
    int i = 0, j = 1;
    int c = 0;
    while (j < n) {
        long long d = a[j] - a[i];
        if (d == k) {
            c++;
            i++;
            j++;
        } else if (d < k) {
            j++;
        } else {
            i++;
            if (i == j) j++;
        }
    }
    printf("%d", c);
    return 0;
}
