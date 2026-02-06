#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 100005;
const int LOGN = 20;

int up[MAXN][LOGN];
bool present[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < LOGN; i++) {
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

void solve() {
    int P;
    if (!(cin >> P)) return;

    for (int i = 0; i < MAXN; i++) {
        adj[i].clear();
        present[i] = false;
    }
    for (int i = 0; i < LOGN; i++) up[0][i] = 0;

    int root = 0;
    for (int i = 0; i < P; i++) {
        int x, y;
        cin >> x >> y;
        if (y == 0) {
            root = x;
        } else {
            adj[y].push_back(x);
        }
        present[x] = true;
    }

    if (root != 0) {
        dfs(root, 0);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int y, x;
            cin >> y >> x;
            present[x] = true;
            up[x][0] = y;
            for (int i = 1; i < LOGN; i++) {
                up[x][i] = up[up[x][i-1]][i-1];
            }
        } else if (type == 1) {
            int x;
            cin >> x;
            present[x] = false;
        } else if (type == 2) {
            int x, k;
            cin >> x >> k;
            if (!present[x]) {
                cout << 0 << "\n";
            } else {
                int curr = x;
                for (int i = 0; i < LOGN; i++) {
                    if ((k >> i) & 1) {
                        curr = up[curr][i];
                    }
                }
                cout << curr << "\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
