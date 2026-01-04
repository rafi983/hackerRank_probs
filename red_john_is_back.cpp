#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int redJohn(int n) {
    vector<long long> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i-1];
        if (i >= 4) {
            dp[i] += dp[i-4];
        }
    }

    long long M = dp[n];

    if (M < 2) return 0;

    vector<bool> is_prime(M + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (long long p = 2; p * p <= M; p++) {
        if (is_prime[p]) {
            for (long long i = p * p; i <= M; i += p)
                is_prime[i] = false;
        }
    }

    int prime_count = 0;
    for (long long p = 2; p <= M; p++) {
        if (is_prime[p]) {
            prime_count++;
        }
    }

    return prime_count;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            cout << redJohn(n) << endl;
        }
    }
    return 0;
}
