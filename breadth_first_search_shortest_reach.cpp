#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q = 0;
    if (!(std::cin >> q)) {
        return 0;
    }

    while (q--) {
        int n = 0;
        int m = 0;
        std::cin >> n >> m;

        std::vector<std::vector<int>> adj(n + 1);
        adj.reserve(n + 1);

        for (int i = 0; i < m; ++i) {
            int u = 0;
            int v = 0;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int s = 0;
        std::cin >> s;

        std::vector<int> dist(n + 1, -1);
        std::queue<int> bfs;
        dist[s] = 0;
        bfs.push(s);

        while (!bfs.empty()) {
            const int cur = bfs.front();
            bfs.pop();

            for (int nxt : adj[cur]) {
                if (dist[nxt] == -1) {
                    dist[nxt] = dist[cur] + 6;
                    bfs.push(nxt);
                }
            }
        }

        bool first = true;
        for (int i = 1; i <= n; ++i) {
            if (i == s) {
                continue;
            }
            if (!first) {
                std::cout << ' ';
            }
            first = false;
            std::cout << dist[i];
        }
        std::cout << '\n';
    }

    return 0;
}

