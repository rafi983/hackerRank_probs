#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_MASK = 1024;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int start_node, end_node;
    cin >> start_node >> end_node;

    vector<vector<bool>> visited(n + 1, vector<bool>(MAX_MASK, false));
    queue<pair<int, int>> q;

    q.push({start_node, 0});
    visited[start_node][0] = true;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int u = curr.first;
        int mask = curr.second;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            int new_mask = mask | w;

            if (!visited[v][new_mask]) {
                visited[v][new_mask] = true;
                q.push({v, new_mask});
            }
        }
    }

    int min_penalty = -1;
    for (int i = 0; i < MAX_MASK; ++i) {
        if (visited[end_node][i]) {
            min_penalty = i;
            break;
        }
    }

    cout << min_penalty << endl;

    return 0;
}

