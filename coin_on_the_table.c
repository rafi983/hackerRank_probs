#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, k;
    if (scanf("%d %d %d", &n, &m, &k) != 3) return 0;

    char **g = (char **)malloc(n * sizeof(char *));
    if (!g) return 0;
    for (int i = 0; i < n; i++) {
        g[i] = (char *)malloc((m + 1) * sizeof(char));
        if (!g[i]) return 0;
        scanf("%s", g[i]);
    }

    int sr = -1, sc = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '*') { sr = i; sc = j; }
        }
    }

    if (sr == 0 && sc == 0) {
        printf("0\n");
        for (int i = 0; i < n; i++) free(g[i]);
        free(g);
        return 0;
    }

    int man = abs(sr) + abs(sc);
    if (man > k) {
        printf("-1\n");
        for (int i = 0; i < n; i++) free(g[i]);
        free(g);
        return 0;
    }

    const int INF = 1000000000;
    int *cur = (int *)malloc(n * m * sizeof(int));
    int *nxt = (int *)malloc(n * m * sizeof(int));
    if (!cur || !nxt) {
        for (int i = 0; i < n; i++) free(g[i]);
        free(g);
        if (cur) free(cur);
        if (nxt) free(nxt);
        return 0;
    }

    for (int i = 0; i < n * m; i++) cur[i] = INF;
    cur[0] = 0;

    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
    char dcch[4] = { 'U', 'D', 'L', 'R' };

    int ans = INF;
    if (sr == 0 && sc == 0) ans = 0;

    for (int t = 0; t < k; t++) {
        for (int i = 0; i < n * m; i++) nxt[i] = INF;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int curCost = cur[i * m + j];
                if (curCost == INF) continue;
                if (i == sr && j == sc) {
                    if (curCost < nxt[i * m + j]) nxt[i * m + j] = curCost;
                    continue;
                }
                for (int d = 0; d < 4; d++) {
                    int ni = i + dr[d];
                    int nj = j + dc[d];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    int cost = curCost + (g[i][j] != dcch[d]);
                    int idx = ni * m + nj;
                    if (cost < nxt[idx]) nxt[idx] = cost;
                }
            }
        }
        int starCost = nxt[sr * m + sc];
        if (starCost < ans) ans = starCost;
        int *tmp = cur; cur = nxt; nxt = tmp;
    }

    if (ans == INF) printf("-1\n"); else printf("%d\n", ans);

    for (int i = 0; i < n; i++);

    return 0;
}
