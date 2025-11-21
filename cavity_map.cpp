#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> cavityMap(const vector<string> &grid) {
    const int n = static_cast<int>(grid.size());
    vector<string> result = grid;

    if (n <= 2) {
        return result;
    }

    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            char current = grid[i][j];
            if (current > grid[i - 1][j] &&
                current > grid[i + 1][j] &&
                current > grid[i][j - 1] &&
                current > grid[i][j + 1]) {
                result[i][j] = 'X';
            }
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<string> grid(n);
    for (string &row : grid) {
        cin >> row;
    }

    vector<string> result = cavityMap(grid);
    for (const string &row : result) {
        cout << row << '\n';
    }

    return 0;
}

