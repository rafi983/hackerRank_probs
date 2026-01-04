#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long MOD = 1000000007;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int legoBlocks(int n, int m) {
    if (n == 0 || m == 0) return 0;

    vector<long long> row_ways(m + 1, 0);
    row_ways[0] = 1;

    for (int i = 1; i <= m; ++i) {
        if (i - 1 >= 0) row_ways[i] = (row_ways[i] + row_ways[i-1]) % MOD;
        if (i - 2 >= 0) row_ways[i] = (row_ways[i] + row_ways[i-2]) % MOD;
        if (i - 3 >= 0) row_ways[i] = (row_ways[i] + row_ways[i-3]) % MOD;
        if (i - 4 >= 0) row_ways[i] = (row_ways[i] + row_ways[i-4]) % MOD;
    }

    vector<long long> total_ways(m + 1);
    for (int i = 1; i <= m; ++i) {
        total_ways[i] = power(row_ways[i], n);
    }

    vector<long long> solid(m + 1);
    for (int i = 1; i <= m; ++i) {
        solid[i] = total_ways[i];
        for (int j = 1; j < i; ++j) {
            long long unstable = (solid[j] * total_ways[i - j]) % MOD;
            solid[i] = (solid[i] - unstable + MOD) % MOD;
        }
    }

    return (int)solid[m];
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            int n, m;
            cin >> n >> m;
            cout << legoBlocks(n, m) << endl;
        }
    }
    return 0;
}
