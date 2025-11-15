#include <stdio.h>
#include <stdlib.h>

static inline int idx(char c) {
    switch (c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
        default: return -1;
    }
}

int steadyGene(const char *gene, int n) {
    int target = n / 4;
    int total[4] = {0};
    for (int i = 0; i < n; i++) total[idx(gene[i])]++;
    int need[4] = {0};
    int neededAny = 0;
    for (int i = 0; i < 4; i++) {
        if (total[i] > target) {
            need[i] = total[i] - target;
            neededAny = 1;
        }
    }
    if (!neededAny) return 0;
    int window[4] = {0};
    int ans = n;
    int l = 0;
    for (int r = 0; r < n; r++) {
        window[idx(gene[r])]++;
        while (window[0] >= need[0] && window[1] >= need[1] && window[2] >= need[2] && window[3] >= need[3]) {
            int len = r - l + 1;
            if (len < ans) ans = len;
            window[idx(gene[l])]--;
            l++;
        }
    }
    return ans;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    char *s = (char *)malloc((n + 1) * sizeof(char));
    if (!s) return 0;
    scanf("%s", s);
    int res = steadyGene(s, n);
    printf("%d\n", res);
    return 0;
}
