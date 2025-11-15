#include <stdio.h>
#include <stdlib.h>

int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;

    while (q--) {
        int n, m;
        if (scanf("%d %d", &n, &m) != 2) return 0;

        int *deg = (int *) calloc(n + 1, sizeof(int));
        int *u = (int *) malloc(m * sizeof(int));
        int *v = (int *) malloc(m * sizeof(int));

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u[i], &v[i]);
            deg[u[i]]++;
            deg[v[i]]++;
        }

        int **adj = (int **) malloc((n + 1) * sizeof(int *));
        int *idx = (int *) calloc(n + 1, sizeof(int));
        for (int i = 1; i <= n; i++) {
            adj[i] = deg[i] ? (int *) malloc(deg[i] * sizeof(int)) : NULL;
        }
        for (int i = 0; i < m; i++) {
            adj[u[i]][idx[u[i]]++] = v[i];
            adj[v[i]][idx[v[i]]++] = u[i];
        }

        int s;
        scanf("%d", &s);

        int *dist = (int *) malloc((n + 1) * sizeof(int));
        for (int i = 1; i <= n; i++) dist[i] = -1;

        int *queue = (int *) malloc(n * sizeof(int));
        int head = 0;
        int tail = 0;

        dist[s] = 0;
        queue[tail++] = s;

        while (head < tail) {
            int cur = queue[head++];
            for (int i = 0; i < deg[cur]; i++) {
                int nxt = adj[cur][i];
                if (dist[nxt] == -1) {
                    dist[nxt] = dist[cur] + 6;
                    queue[tail++] = nxt;
                }
            }
        }

        int first = 1;
        for (int i = 1; i <= n; i++) {
            if (i == s) continue;
            if (!first) printf(" ");
            first = 0;
            printf("%d", dist[i]);
        }
        printf("\n");

        for (int i = 1; i <= n; i++) if (adj[i]) free(adj[i]);

    }

    return 0;
}
