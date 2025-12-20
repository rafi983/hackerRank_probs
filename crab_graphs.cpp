#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to;
    int capacity;
    int flow;
    int rev;
};

vector<vector<Edge>> adj;
vector<int> level;
vector<int> ptr;

void add_edge(int from, int to, int cap) {
    adj[from].push_back({to, cap, 0, (int)adj[to].size()});
    adj[to].push_back({from, 0, 0, (int)adj[from].size() - 1});
}

bool bfs(int s, int t) {
    fill(level.begin(), level.end(), -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& edge : adj[v]) {
            if (edge.capacity - edge.flow > 0 && level[edge.to] == -1) {
                level[edge.to] = level[v] + 1;
                q.push(edge.to);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int v, int t, int pushed) {
    if (pushed == 0) return 0;
    if (v == t) return pushed;
    for (int& cid = ptr[v]; cid < (int)adj[v].size(); ++cid) {
        auto& edge = adj[v][cid];
        int tr = edge.to;
        if (level[v] + 1 != level[tr] || edge.capacity - edge.flow == 0) continue;
        int push = dfs(tr, t, min(pushed, edge.capacity - edge.flow));
        if (push == 0) continue;
        edge.flow += push;
        adj[tr][edge.rev].flow -= push;
        return push;
    }
    return 0;
}

int dinic(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {
        fill(ptr.begin(), ptr.end(), 0);
        while (int pushed = dfs(s, t, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

int N, T, M;
vector<vector<int>> flow_adj;
vector<int> in_degree;
vector<bool> visited;
vector<vector<int>> dp;

void solve_tree(int u) {
    visited[u] = true;

    int sum_unused_head = 0;
    vector<int> diffs;

    for (int v : flow_adj[u]) {
        solve_tree(v);
        int val_unused_head = max(dp[v][0], dp[v][2]);
        sum_unused_head += val_unused_head;
        diffs.push_back(dp[v][1] - val_unused_head);
    }

    dp[u][0] = sum_unused_head;
    dp[u][1] = 1 + sum_unused_head;

    if (diffs.empty()) {
        dp[u][2] = -INF;
    } else {
        sort(diffs.rbegin(), diffs.rend());
        int current_gain = diffs[0];
        for (size_t i = 1; i < diffs.size(); ++i) {
            if (diffs[i] > 0) current_gain += diffs[i];
        }
        dp[u][2] = 1 + sum_unused_head + current_gain;
    }
}

void solve() {
    if (!(cin >> N >> T >> M)) return;

    int S = 0;
    int D = 2 * N + 1;
    adj.assign(D + 1, vector<Edge>());
    level.resize(D + 1);
    ptr.resize(D + 1);

    for (int i = 1; i <= N; ++i) {
    }

    vector<pair<int, int>> edges;
    vector<int> degree(N + 1, 0);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        degree[u]++;
        degree[v]++;
    }

    for (int i = 1; i <= N; ++i) {
        add_edge(S, i, min(degree[i], T));
        add_edge(N + i, D, 1);
    }

    for (auto& e : edges) {
        int u = e.first;
        int v = e.second;
        add_edge(u, N + v, 1);
        add_edge(v, N + u, 1);
    }

    dinic(S, D);

    flow_adj.assign(N + 1, vector<int>());
    in_degree.assign(N + 1, 0);

    for (int u = 1; u <= N; ++u) {
        for (auto& e : adj[u]) {
            if (e.to > N && e.to <= 2 * N && e.flow == 1) {
                int v = e.to - N;
                flow_adj[u].push_back(v);
                in_degree[v]++;
            }
        }
    }

    visited.assign(N + 1, false);
    dp.assign(N + 1, vector<int>(3));

    int total_vertices = 0;

    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] == 0 && !visited[i]) {
            solve_tree(i);
            total_vertices += max(dp[i][0], dp[i][2]);
        }
    }

    vector<int> parent(N + 1, 0);
    for (int u = 1; u <= N; ++u) {
        for (int v : flow_adj[u]) {
            parent[v] = u;
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            int curr = i;
            vector<int> path;
            vector<int> visited_in_path(N + 1, -1);
            int step = 0;

            int cycle_start_node = -1;
            while (true) {
                if (visited_in_path[curr] != -1) {
                    cycle_start_node = curr;
                    break;
                }
                visited_in_path[curr] = step++;
                path.push_back(curr);
                curr = parent[curr];
            }

            vector<int> cycle_nodes;
            int start_idx = visited_in_path[cycle_start_node];
            for(size_t k = start_idx; k < path.size(); ++k) {
                cycle_nodes.push_back(path[k]);
            }

            vector<int> component_nodes;
            queue<int> q_comp;
            q_comp.push(cycle_start_node);
            vector<bool> comp_visited(N + 1, false);
            comp_visited[cycle_start_node] = true;
            component_nodes.push_back(cycle_start_node);

            while(!q_comp.empty()){
                int u_node = q_comp.front(); q_comp.pop();
                for(int v_node : flow_adj[u_node]){
                    if(!comp_visited[v_node]){
                        comp_visited[v_node] = true;
                        q_comp.push(v_node);
                        component_nodes.push_back(v_node);
                    }
                }
            }

            int max_comp_val = 0;

            for(int node : cycle_nodes) {
                int u_edge = parent[node];
                int v_edge = node;

                auto it = find(flow_adj[u_edge].begin(), flow_adj[u_edge].end(), v_edge);
                if(it != flow_adj[u_edge].end()) {
                    flow_adj[u_edge].erase(it);

                    for(int c_node : component_nodes) visited[c_node] = false;

                    solve_tree(v_edge);
                    max_comp_val = max(max_comp_val, max(dp[v_edge][0], dp[v_edge][2]));

                    flow_adj[u_edge].push_back(v_edge);
                }
            }
            total_vertices += max_comp_val;

            for(int c_node : component_nodes) visited[c_node] = true;
        }
    }

    cout << total_vertices << endl;
}

int main() {
    int C;
    if (cin >> C) {
        while (C--) {
            solve();
        }
    }
    return 0;
}
