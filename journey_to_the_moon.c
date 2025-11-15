#include <stdio.h>
#include <stdlib.h>

static int *parent;
static int *sz;

static int find(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

static void unite(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra == rb) return;
    if (sz[ra] < sz[rb]) { int t = ra; ra = rb; rb = t; }
    parent[rb] = ra;
    sz[ra] += sz[rb];
}

int main() {
    int n, p;
    if (scanf("%d %d", &n, &p) != 2) return 0;
    parent = (int*)malloc(n * sizeof(int));
    sz = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) { parent[i] = i; sz[i] = 1; }
    for (int i = 0; i < p; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        unite(a, b);
    }
    long long result = 0;
    long long remaining = n;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) {
            long long s = sz[i];
            remaining -= s;
            result += s * remaining;
        }
    }
    printf("%lld\n", result);

    return 0;
}

