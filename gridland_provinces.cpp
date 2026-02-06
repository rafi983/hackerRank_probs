#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 605;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll P1 = 31;
const ll P2 = 37;

ll pow1[MAXN * 2], pow2[MAXN * 2];

void precompute() {
    pow1[0] = 1;
    pow2[0] = 1;
    for (int i = 1; i < MAXN * 2; i++) {
        pow1[i] = (pow1[i - 1] * P1) % MOD1;
        pow2[i] = (pow2[i - 1] * P2) % MOD2;
    }
}

struct HashResult {
    ll h1, h2;
    int len;
};

struct StringHash {
    vector<ll> h1, h2;
    string s;

    StringHash() {}
    StringHash(string _s) : s(_s) {
        int n = s.length();
        h1.resize(n + 1, 0);
        h2.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * P1 + (s[i] - 'a' + 1)) % MOD1;
            h2[i + 1] = (h2[i] * P2 + (s[i] - 'a' + 1)) % MOD2;
        }
    }

    HashResult get(int l, int r) { // [l, r] inclusive 0-based
        if (l > r) return {0, 0, 0};
        ll val1 = (h1[r + 1] - h1[l] * pow1[r - l + 1]) % MOD1;
        if (val1 < 0) val1 += MOD1;
        ll val2 = (h2[r + 1] - h2[l] * pow2[r - l + 1]) % MOD2;
        if (val2 < 0) val2 += MOD2;
        return {val1, val2, r - l + 1};
    }
};

HashResult combine(const HashResult& left, const HashResult& right) {
    if (left.len == 0) return right;
    if (right.len == 0) return left;
    ll nh1 = (left.h1 * pow1[right.len] + right.h1) % MOD1;
    ll nh2 = (left.h2 * pow2[right.len] + right.h2) % MOD2;
    return {nh1, nh2, left.len + right.len};
}

// Global set for the province
vector<pair<ll, ll>> results;
int N;
string S[2];
string S_rev[2];
StringHash SH[2], SH_rev[2];

void process(const vector<string>& grid) {
    int n = grid[0].size();
    N = n;
    S[0] = grid[0]; S[1] = grid[1];
    S_rev[0] = S[0]; reverse(S_rev[0].begin(), S_rev[0].end());
    S_rev[1] = S[1]; reverse(S_rev[1].begin(), S_rev[1].end());

    SH[0] = StringHash(S[0]);
    SH[1] = StringHash(S[1]);
    SH_rev[0] = StringHash(S_rev[0]);
    SH_rev[1] = StringHash(S_rev[1]);

    vector<vector<HashResult>> r_turn(n + 1, vector<HashResult>(2));

    // Base case: col = n (empty)
    r_turn[n][0] = {0, 0, 0};
    r_turn[n][1] = {0, 0, 0};

    for (int j = n - 1; j >= 0; j--) {
        for (int row = 0; row < 2; row++) {


             HashResult p1, p2;
             if (row == 0) {
                 p1 = SH[0].get(j, n - 1);

                 p2 = SH_rev[1].get(0, n - 1 - j);
             } else {
                 p1 = SH[1].get(j, n - 1);
                 // S[0][j..N-1] reversed.
                 p2 = SH_rev[0].get(0, n - 1 - j);
             }
             r_turn[j][row] = combine(p1, p2);
        }
    }

    // Main loop
    for (int k = 0; k < n; k++) {
        for (int r = 0; r < 2; r++) {


            HashResult L;
            if (r == 0) {
                HashResult part1 = SH_rev[0].get(n - 1 - k, n - 1);
                HashResult part2 = SH[1].get(0, k);
                L = combine(part1, part2);
            } else {
                HashResult part1 = SH_rev[1].get(n - 1 - k, n - 1);
                HashResult part2 = SH[0].get(0, k);
                L = combine(part1, part2);
            }


            HashResult current_snake = {0, 0, 0};

            for (int j = k; j < n; j++) {
                // If j == k, snake is empty. We just append Right U-turn at k+1.
                // If j > k, we add columns to snake.

                if (j > k) {


                    int col = j;
                    int entry_row = (1 - r + (j - (k + 1))) % 2; // Check this logic


                    HashResult h_char1, h_char2;
                    // Visit (entry_row, col)
                    h_char1 = SH[entry_row].get(col, col);
                    // Visit (1-entry_row, col)
                    h_char2 = SH[1 - entry_row].get(col, col);

                    current_snake = combine(current_snake, combine(h_char1, h_char2));
                }



                int u_turn_start_row = (1 - r + (j - k)) % 2;
                HashResult R = r_turn[j + 1][u_turn_start_row];

                HashResult combined = combine(L, combine(current_snake, R));
                results.push_back({combined.h1, combined.h2});
            }
        }
    }
}

void solve() {
    int P;
    if (!(cin >> P)) return;
    precompute();

    while (P--) {
        int R, C;


        cin >> C;
        string s1, s2;
        cin >> s1 >> s2;

        results.clear();
        results.reserve(2LL * C * C); // Reserve memory to avoid reallocations

        process({s1, s2});

        // Reverse cols
        string r1 = s1, r2 = s2;
        reverse(r1.begin(), r1.end());
        reverse(r2.begin(), r2.end());

        process({r1, r2});

        sort(results.begin(), results.end());
        results.erase(unique(results.begin(), results.end()), results.end());

        cout << results.size() << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
