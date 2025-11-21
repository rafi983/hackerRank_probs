#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    vector<vector<int>> adj(n + 1);
    adj.reserve(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n + 1, 0);
    vector<int> order;
    order.reserve(n);
    vector<int> stack;
    stack.reserve(n);

    stack.push_back(1);
    parent[1] = 0;

    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();
        order.push_back(u);
        for (int v : adj[u]) {
            if (v == parent[u]) {
                continue;
            }
            parent[v] = u;
            stack.push_back(v);
        }
    }

    vector<int> subtreeSize(n + 1, 1);
    int cuts = 0;

    for (int i = static_cast<int>(order.size()) - 1; i >= 0; --i) {
        int u = order[i];
        if (parent[u] != 0) {
            subtreeSize[parent[u]] += subtreeSize[u];
            if ((subtreeSize[u] & 1) == 0) {
                ++cuts;
            }
        }
    }

    cout << cuts << '\n';
    return 0;
}

