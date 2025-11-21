#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long bricksGame(const vector<long long> &a) {
    const int n = static_cast<int>(a.size());
    if (n <= 3) {
        long long s = 0;
        for (long long v : a) s += v;
        return s;
    }

    vector<long long> dp(n + 4, 0);
    vector<long long> suf(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i];

    for (int i = n - 1; i >= 0; --i) {
        long long mn = min({dp[i + 1], dp[i + 2], dp[i + 3]});
        dp[i] = suf[i] - mn;
    }

    return dp[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        if (!(cin >> n)) return 0;
        vector<long long> a(n);
        for (long long &v : a) cin >> v;
        cout << bricksGame(a) << '\n';
    }
    return 0;
}

