#include <iostream>
#include <vector>
#include <numeric>

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

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

const int MAXN = 300005;
long long fact[MAXN];

void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

struct BIT {
    int n;
    vector<int> tree;

    BIT(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomputeFactorials();

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n + 1);
    vector<bool> present(n + 1, false);
    int k = 0; // number of zeros

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] != 0) {
            present[a[i]] = true;
        } else {
            k++;
        }
    }

    vector<int> missing_count_prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        missing_count_prefix[i] = missing_count_prefix[i - 1];
        if (!present[i]) {
            missing_count_prefix[i]++;
        }
    }

    long long total_sum = fact[k];

    BIT bit(n);
    long long sum_G = 0;
    long long z_R = 0;

    long long fact_k = fact[k];
    long long fact_k_minus_1 = (k > 0) ? fact[k - 1] : 0;
    long long term4_coeff = 0;
    if (k >= 2) {
        term4_coeff = (fact[k] * modInverse(2)) % MOD;
    }

    for (int i = n; i >= 1; --i) {
        long long n_minus_i_fact = fact[n - i];

        if (a[i] != 0) {
            // Term 1: Fixed vs Fixed to right
            long long cnt_fixed_smaller = bit.query(a[i] - 1);
            long long t1 = (cnt_fixed_smaller * fact_k) % MOD;
            t1 = (t1 * n_minus_i_fact) % MOD;

            // Term 2: Fixed vs Missing to right
            long long cnt_missing_smaller = missing_count_prefix[a[i] - 1];
            long long t2 = 0;
            if (k > 0) {
                t2 = (cnt_missing_smaller * z_R) % MOD;
                t2 = (t2 * fact_k_minus_1) % MOD;
                t2 = (t2 * n_minus_i_fact) % MOD;
            }

            total_sum = (total_sum + t1 + t2) % MOD;

            bit.add(a[i], 1);
            long long g_val = k - missing_count_prefix[a[i]];
            sum_G = (sum_G + g_val) % MOD;

        } else {
            // a[i] == 0
            // Term 3: Missing (at i) vs Fixed to right
            long long t3 = 0;
            if (k > 0) {
                t3 = (sum_G * fact_k_minus_1) % MOD;
                t3 = (t3 * n_minus_i_fact) % MOD;
            }

            // Term 4: Missing (at i) vs Missing to right
            long long t4 = 0;
            if (k >= 2) {
                t4 = (z_R * term4_coeff) % MOD;
                t4 = (t4 * n_minus_i_fact) % MOD;
            }

            total_sum = (total_sum + t3 + t4) % MOD;

            z_R++;
        }
    }

    cout << total_sum << endl;

    return 0;
}

