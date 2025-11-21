#include <iostream>
#include <vector>
#include <array>

using namespace std;

namespace {
constexpr array<int, 8> kDr = { -1, -1, -1, 0, 0, 1, 1, 1 };
constexpr array<int, 8> kDc = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool inBounds(int r, int c, int n, int m) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

int dfs(int r, int c, int n, int m, const vector<vector<int>> &grid, vector<vector<bool>> &visited) {
    if (!inBounds(r, c, n, m) || visited[r][c] || grid[r][c] == 0) {
        return 0;
    }

    visited[r][c] = true;
    int size = 1;

    for (int dir = 0; dir < 8; ++dir) {
        size += dfs(r + kDr[dir], c + kDc[dir], n, m, grid, visited);
    }

    return size;
}

int connectedCell(const vector<vector<int>> &grid) {
    const int n = static_cast<int>(grid.size());
    const int m = n ? static_cast<int>(grid[0].size()) : 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int maxRegion = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                maxRegion = max(maxRegion, dfs(i, j, n, m, grid, visited));
            }
        }
    }
    return maxRegion;
}
}  // namespace

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << connectedCell(grid) << '\n';
    return 0;
}

