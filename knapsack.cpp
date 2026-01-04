#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int unboundedKnapsack(int k, vector<int> arr) {
    vector<bool> dp(k + 1, false);
    dp[0] = true;

    for (int val : arr) {
        if (val == 0) continue; // Skip 0 as it doesn't affect the sum
        for (int j = val; j <= k; ++j) {
            if (dp[j - val]) {
                dp[j] = true;
            }
        }
    }

    for (int i = k; i >= 0; --i) {
        if (dp[i]) {
            return i;
        }
    }
    return 0;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            int n, k;
            cin >> n >> k;
            vector<int> arr(n);
            for (int i = 0; i < n; ++i) {
                cin >> arr[i];
            }
            cout << unboundedKnapsack(k, arr) << endl;
        }
    }
    return 0;
}
