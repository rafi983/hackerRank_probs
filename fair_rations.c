#include <stdio.h>

static int fairRations(int *B, int n) {
    int distributed = 0;
    for (int i = 0; i < n - 1; i++) {
        if (B[i] & 1) {
            B[i]++;
            B[i + 1]++;
            distributed += 2;
        }
    }
    if (n > 0 && (B[n - 1] & 1)) return -1;
    return distributed;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[10000];
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) arr[i] = 0;
    }
    int res = fairRations(arr, n);
    if (res < 0) {
        printf("NO\n");
    } else {
        printf("%d\n", res);
    }
    return 0;
}

