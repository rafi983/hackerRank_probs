#include <bits/stdc++.h>
using namespace std;

long long primsMST(int n, const vector<vector<pair<int, int>>> &adj, int start) {
    vector<int> visited(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);
    long long total = 0;
    int picked = 0;

    while (!pq.empty() && picked < n) {
        auto [w, u] = pq.top();
        pq.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = 1;
        total += w;
        picked++;

        for (const auto &[v, weight] : adj[u]) {
            if (!visited[v]) {
                pq.emplace(weight, v);
            }
        }
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int start;
    cin >> start;

    cout << primsMST(n, adj, start) << '\n';
    return 0;
}

