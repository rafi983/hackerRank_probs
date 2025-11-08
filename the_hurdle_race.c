#include <stdio.h>

static int hurdleRace(int k, int n, int height[]) {
    int max = 0;
    for (int i = 0; i < n; i++) if (height[i] > max) max = height[i];
    int diff = max - k;
    return diff > 0 ? diff : 0;
}

int main(void) {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;
    int ans = 0;
    if (n > 0) {
        int cur;
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &cur) != 1) cur = 0;
            if (cur > max) max = cur;
        }
        int diff = max - k;
        ans = diff > 0 ? diff : 0;
    }
    printf("%d\n", ans);
    return 0;
}

