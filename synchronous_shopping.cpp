#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

const int INF = 1e9;

struct State {
    int u;
    int mask;
    int time;

    bool operator>(const State& other) const {
        return time > other.time;
    }
};

int main() {
    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<int> fish_mask(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        while (t--) {
            int fish_type;
            cin >> fish_type;
            fish_mask[i] |= (1 << (fish_type - 1));
        }
    }

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int num_states = 1 << k;
    vector<vector<int>> dist(n + 1, vector<int>(num_states, INF));

    priority_queue<State, vector<State>, greater<State>> pq;

    int start_mask = fish_mask[1];
    dist[1][start_mask] = 0;
    pq.push({1, start_mask, 0});

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        int u = current.u;
        int mask = current.mask;
        int time = current.time;

        if (time > dist[u][mask]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            int new_mask = mask | fish_mask[v];
            int new_time = time + w;

            if (new_time < dist[v][new_mask]) {
                dist[v][new_mask] = new_time;
                pq.push({v, new_mask, new_time});
            }
        }
    }

    int ans = INF;
    int all_fish = (1 << k) - 1;

    for (int i = 0; i < num_states; ++i) {
        if (dist[n][i] == INF) continue;
        for (int j = i; j < num_states; ++j) {
            if (dist[n][j] == INF) continue;
            if ((i | j) == all_fish) {
                ans = min(ans, max(dist[n][i], dist[n][j]));
            }
        }
    }

    cout << ans << endl;

    return 0;
}

