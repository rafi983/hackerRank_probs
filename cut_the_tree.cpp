#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
vector<int> data_values;
vector<vector<int>> adj;
vector<long long> subtree_sum;
long long total_sum = 0;
long long min_diff;

void dfs(int u, int p) {
    subtree_sum[u] = data_values[u - 1];
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            subtree_sum[u] += subtree_sum[v];
        }
    }
}

int main() {
    if (!(cin >> n)) return 0;

    data_values.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> data_values[i];
        total_sum += data_values[i];
    }

    adj.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    subtree_sum.resize(n + 1);
    dfs(1, 0);

    min_diff = total_sum;

    for (int i = 2; i <= n; ++i) {
        long long current_subtree_sum = subtree_sum[i];
        long long other_part_sum = total_sum - current_subtree_sum;
        long long diff = abs(current_subtree_sum - other_part_sum);
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    cout << min_diff << endl;

    return 0;
}
