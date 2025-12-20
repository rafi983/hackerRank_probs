#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 2e9;

void getCost(int g_nodes, const vector<int>& g_from, const vector<int>& g_to, const vector<int>& g_weight) {
    vector<vector<pair<int, int>>> adj(g_nodes + 1);
    for (size_t i = 0; i < g_from.size(); ++i) {
        adj[g_from[i]].push_back({g_to[i], g_weight[i]});
        adj[g_to[i]].push_back({g_from[i], g_weight[i]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(g_nodes + 1, INF);

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        if (u == g_nodes) break;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            int new_dist = max(d, w);

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    if (dist[g_nodes] == INF) {
        cout << "NO PATH EXISTS" << endl;
    } else {
        cout << dist[g_nodes] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int g_nodes, g_edges;
    if (cin >> g_nodes >> g_edges) {
        vector<int> g_from(g_edges);
        vector<int> g_to(g_edges);
        vector<int> g_weight(g_edges);

        for (int i = 0; i < g_edges; ++i) {
            cin >> g_from[i] >> g_to[i] >> g_weight[i];
        }

        getCost(g_nodes, g_from, g_to, g_weight);
    }
    return 0;
}

