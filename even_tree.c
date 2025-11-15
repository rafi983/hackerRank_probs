#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int *deg = (int *) calloc(n + 1, sizeof(int));
    int *a   = (int *) malloc(m * sizeof(int));
    int *b   = (int *) malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a[i], &b[i]);
        deg[a[i]]++;
        deg[b[i]]++;
    }

    int **adj = (int **) malloc((n + 1) * sizeof(int *));
    int *pos  = (int *) calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        adj[i] = deg[i] ? (int *) malloc(deg[i] * sizeof(int)) : NULL;
    }

    for (int i = 0; i < m; i++) {
        adj[a[i]][pos[a[i]]++] = b[i];
        adj[b[i]][pos[b[i]]++] = a[i];
    }

    int *parent = (int *) malloc((n + 1) * sizeof(int));
    int *order  = (int *) malloc(n * sizeof(int));
    int *stack  = (int *) malloc(n * sizeof(int));

    int top    = 0;
    int ordLen = 0;

    stack[top++] = 1;
    parent[1]    = 0;

    while (top > 0) {
        int u = stack[--top];
        order[ordLen++] = u;
        for (int i = 0; i < deg[u]; i++) {
            int v = adj[u][i];
            if (v == parent[u]) continue;
            parent[v] = u;
            stack[top++] = v;
        }
    }

    int *sz = (int *) malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        sz[i] = 1;
    }

    int cuts = 0;

    for (int i = ordLen - 1; i >= 0; i--) {
        int u = order[i];
        if (parent[u]) {
            sz[parent[u]] += sz[u];
            if ((sz[u] & 1) == 0) {
                cuts++;
            }
        }
    }

    printf("%d\n", cuts);

    for (int i = 1; i <= n; i++) {
        if (adj[i]) free(adj[i]);
    }


    return 0;
}
