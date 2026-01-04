#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


int boardCutting(vector<int> cost_y, vector<int> cost_x) {
    sort(cost_y.begin(), cost_y.end(), greater<int>());
    sort(cost_x.begin(), cost_x.end(), greater<int>());

    long long total_cost = 0;
    long long h_segments = 1;
    long long v_segments = 1;
    long long MOD = 1000000007;

    int i = 0; // index for cost_y
    int j = 0; // index for cost_x

    while (i < cost_y.size() && j < cost_x.size()) {
        if (cost_y[i] >= cost_x[j]) {
            // Choose horizontal cut
            long long cost = cost_y[i];
            total_cost = (total_cost + cost * v_segments) % MOD;
            h_segments++;
            i++;
        } else {
            // Choose vertical cut
            long long cost = cost_x[j];
            total_cost = (total_cost + cost * h_segments) % MOD;
            v_segments++;
            j++;
        }
    }

    // Process remaining horizontal cuts
    while (i < cost_y.size()) {
        long long cost = cost_y[i];
        total_cost = (total_cost + cost * v_segments) % MOD;
        h_segments++;
        i++;
    }

    // Process remaining vertical cuts
    while (j < cost_x.size()) {
        long long cost = cost_x[j];
        total_cost = (total_cost + cost * h_segments) % MOD;
        v_segments++;
        j++;
    }

    return (int)total_cost;
}

int main() {
    int q;
    if (cin >> q) {
        while (q--) {
            int m, n;
            cin >> m >> n;
            vector<int> cost_y(m - 1);
            for (int i = 0; i < m - 1; ++i) {
                cin >> cost_y[i];
            }
            vector<int> cost_x(n - 1);
            for (int i = 0; i < n - 1; ++i) {
                cin >> cost_x[i];
            }
            cout << boardCutting(cost_y, cost_x) << endl;
        }
    }
    return 0;
}
