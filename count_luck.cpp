#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace {
constexpr int DR[4] = {-1, 0, 0, 1};
constexpr int DC[4] = {0, -1, 1, 0};

int dfs(int r, int c,
        const vector<string> &grid,
        vector<vector<int>> &visited,
        int rows,
        int cols) {
    if (grid[r][c] == '*') {
        return 0;
    }

    visited[r][c] = 1;
    vector<pair<int, int>> next;
    next.reserve(4);

    for (int dir = 0; dir < 4; ++dir) {
        int nr = r + DR[dir];
        int nc = c + DC[dir];
        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
            continue;
        }
        if (grid[nr][nc] == 'X' || visited[nr][nc]) {
            continue;
        }
        next.emplace_back(nr, nc);
    }

    for (const auto &cell : next) {
        int result = dfs(cell.first, cell.second, grid, visited, rows, cols);
        if (result != -1) {
            return result + (next.size() > 1 ? 1 : 0);
        }
    }

    return -1;
}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) {
        return 0;
    }

    while (t--) {
        int rows, cols;
        if (!(cin >> rows >> cols)) {
            return 0;
        }

        vector<string> grid(rows);
        for (string &row : grid) {
            cin >> row;
        }

        int guess;
        cin >> guess;

        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int start_r = -1;
        int start_c = -1;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 'M') {
                    start_r = i;
                    start_c = j;
                }
            }
        }

        int decisions = dfs(start_r, start_c, grid, visited, rows, cols);
        if (decisions == guess) {
            cout << "Impressed\n";
        } else {
            cout << "Oops!\n";
        }
    }

    return 0;
}

