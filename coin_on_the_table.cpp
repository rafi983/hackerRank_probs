#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <limits>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    if (!(cin >> n >> m >> k)) {
        return 0;
    }

    vector<string> grid(n);
    for (string &row : grid) {
        cin >> row;
    }

    int sr = -1;
    int sc = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '*') {
                sr = i;
                sc = j;
            }
        }
    }

    if (sr == -1 || sc == -1) {
        cout << -1 << '\n';
        return 0;
    }

    if (sr == 0 && sc == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int manhattan = abs(sr) + abs(sc);
    if (manhattan > k) {
        cout << -1 << '\n';
        return 0;
    }

    const int totalCells = n * m;
    const int INF = numeric_limits<int>::max() / 4;
    vector<int> cur(totalCells, INF);
    vector<int> nxt(totalCells, INF);
    cur[0] = 0;

    const array<int, 4> dr = { -1, 1, 0, 0 };
    const array<int, 4> dc = { 0, 0, -1, 1 };
    const array<char, 4> moveChar = { 'U', 'D', 'L', 'R' };

    int ans = INF;

    for (int step = 0; step < k; ++step) {
        fill(nxt.begin(), nxt.end(), INF);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                const int idx = i * m + j;
                const int curCost = cur[idx];
                if (curCost == INF) {
                    continue;
                }
                if (i == sr && j == sc) {
                    nxt[idx] = min(nxt[idx], curCost);
                    continue;
                }
                for (int d = 0; d < 4; ++d) {
                    const int ni = i + dr[d];
                    const int nj = j + dc[d];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                        continue;
                    }
                    const int nidx = ni * m + nj;
                    const int extra = (grid[i][j] == moveChar[d]) ? 0 : 1;
                    const int nextCost = curCost + extra;
                    if (nextCost < nxt[nidx]) {
                        nxt[nidx] = nextCost;
                    }
                }
            }
        }
        ans = min(ans, nxt[sr * m + sc]);
        swap(cur, nxt);
    }

    if (ans == INF) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}

