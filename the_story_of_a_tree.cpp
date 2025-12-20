#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> adj;
set<pair<int, int>> guesses;
int k;
int total_wins;

// DFS to calculate score for root = 1
void dfs_initial(int u, int p, int& current_score) {
    for (int v : adj[u]) {
        if (v != p) {
            if (guesses.count({u, v})) {
                current_score++;
            }
            dfs_initial(v, u, current_score);
        }
    }
}

// DFS to propagate scores
void dfs_reroot(int u, int p, int current_score) {
    if (current_score >= k) {
        total_wins++;
    }

    for (int v : adj[u]) {
        if (v != p) {
            int next_score = current_score;
            if (guesses.count({u, v})) {
                next_score--;
            }
            if (guesses.count({v, u})) {
                next_score++;
            }
            dfs_reroot(v, u, next_score);
        }
    }
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    if (!(cin >> n)) return;
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int g;
    cin >> g >> k;
    guesses.clear();
    for (int i = 0; i < g; ++i) {
        int u, v;
        cin >> u >> v;
        guesses.insert({u, v});
    }

    int initial_score = 0;
    dfs_initial(1, 0, initial_score);

    total_wins = 0;
    dfs_reroot(1, 0, initial_score);

    int common = gcd(total_wins, n);
    cout << (total_wins / common) << "/" << (n / common) << endl;
}

int main() {
    int q;
    if (cin >> q) {
        while (q--) {
            solve();
        }
    }
    return 0;
}

