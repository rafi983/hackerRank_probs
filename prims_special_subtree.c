#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *node;
    int *weight;
    int size;
} Heap;

static void heap_swap(Heap *h, int i, int j) {
    int tn = h->node[i];
    int tw = h->weight[i];
    h->node[i] = h->node[j];
    h->weight[i] = h->weight[j];
    h->node[j] = tn;
    h->weight[j] = tw;
}

static void heap_push(Heap *h, int n, int w) {
    int i = h->size++;
    h->node[i] = n;
    h->weight[i] = w;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->weight[p] <= h->weight[i]) break;
        heap_swap(h, p, i);
        i = p;
    }
}

static int heap_pop(Heap *h, int *out_node, int *out_weight) {
    if (h->size == 0) return 0;
    *out_node = h->node[0];
    *out_weight = h->weight[0];
    h->size--;
    if (h->size > 0) {
        h->node[0] = h->node[h->size];
        h->weight[0] = h->weight[h->size];
        int i = 0;
        for (;;) {
            int l = 2 * i + 1;
            int r = l + 1;
            if (l >= h->size) break;
            int m = l;
            if (r < h->size && h->weight[r] < h->weight[l]) m = r;
            if (h->weight[i] <= h->weight[m]) break;
            heap_swap(h, i, m);
            i = m;
        }
    }
    return 1;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int *head = (int *) malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) head[i] = -1;

    int cap = 2 * m;
    int *to = (int *) malloc(cap * sizeof(int));
    int *w  = (int *) malloc(cap * sizeof(int));
    int *next = (int *) malloc(cap * sizeof(int));

    int idx = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        to[idx] = b; w[idx] = c; next[idx] = head[a]; head[a] = idx++;
        to[idx] = a; w[idx] = c; next[idx] = head[b]; head[b] = idx++;
    }

    int start;
    scanf("%d", &start);

    int *visited = (int *) malloc((n + 1) * sizeof(int));
    int *dist    = (int *) malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) { visited[i] = 0; dist[i] = 2147483647; }

    Heap heap;
    heap.node = (int *) malloc((2 * m + 5) * sizeof(int));
    heap.weight = (int *) malloc((2 * m + 5) * sizeof(int));
    heap.size = 0;

    dist[start] = 0;
    heap_push(&heap, start, 0);

    long long total = 0;
    int count = 0;

    while (heap.size > 0 && count < n) {
        int u, uw;
        if (!heap_pop(&heap, &u, &uw)) break;
        if (visited[u]) continue;
        visited[u] = 1;
        total += uw;
        count++;
        for (int e = head[u]; e != -1; e = next[e]) {
            int v = to[e];
            int ww = w[e];
            if (!visited[v] && ww < dist[v]) {
                dist[v] = ww;
                heap_push(&heap, v, ww);
            }
        }
    }

    printf("%lld\n", total);
    return 0;
}

