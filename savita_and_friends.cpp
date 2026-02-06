#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long weight;
};

struct Node {
    long long da;
    long long db;
    int id;
};

bool compareNodes(const Node& a, const Node& b) {
    if (a.da != b.da) return a.da < b.da;
    return a.db < b.db;
}

void dijkstra(int start, int n, const vector<vector<Edge>>& adj, vector<long long>& dist) {
    dist.assign(n + 1, INF);
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            if (dist[u] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[u] + edge.weight;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }
}

void solve() {
    int N, M, K;
    if (!(cin >> N >> M >> K)) return;

    vector<vector<Edge>> adj(N + 1);
    int u_k = -1, v_k = -1;
    long long w_k = -1;

    for (int i = 1; i <= M; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        if (i == K) {
            u_k = u;
            v_k = v;
            w_k = w;
        }
    }

    vector<long long> distA, distB;
    dijkstra(u_k, N, adj, distA);
    dijkstra(v_k, N, adj, distB);

    vector<Node> nodes;
    for (int i = 1; i <= N; ++i) {
        nodes.push_back({distA[i], distB[i], i});
    }

    sort(nodes.begin(), nodes.end(), compareNodes);

    vector<long long> suffixMaxB(N);
    long long maxB = -1;
    for (int i = N - 1; i >= 0; --i) {
        maxB = max(maxB, nodes[i].db);
        suffixMaxB[i] = maxB;
    }

    double minMaxDist = -1.0;
    double bestX = -1.0;
    double eps = 1e-9;

    // Check x=0 (At node u_k)
    long long maxDA = 0;
    for(const auto& nd : nodes) maxDA = max(maxDA, nd.da);

    minMaxDist = (double)maxDA;
    bestX = 0.0;

    // Check x=W (At node v_k)
    // At x=W, max dist is max(distB).
    long long maxDB = -1;
    if(N > 0) maxDB = suffixMaxB[0];
    else maxDB = 0; // Should not happen for N>=1

    if ((double)maxDB < minMaxDist - eps) {
        minMaxDist = (double)maxDB;
        bestX = (double)w_k;
    }

    for (int i = 0; i < N - 1; ++i) {
        long long A = nodes[i].da;
        long long B = suffixMaxB[i+1];

        double x = (double)(w_k + B - A) / 2.0;
        double val = (double)(w_k + B + A) / 2.0;

        if (x >= -eps && x <= (double)w_k + eps) {
            // Keep x within bounds [0, W]
            if (x < 0) x = 0;
            if (x > w_k) x = w_k;


            if (val < minMaxDist - eps) {
                minMaxDist = val;
                bestX = x;
            } else if (abs(val - minMaxDist) < eps) {
                if (x < bestX - eps) {
                    bestX = x;
                }
            }
        }
    }

    cout << fixed << setprecision(5) << bestX << " " << minMaxDist << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
