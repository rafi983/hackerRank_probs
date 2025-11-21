#include <iostream>
#include <vector>
#include <string>

using namespace std;

string gridSearch(const vector<string> &grid, const vector<string> &pattern) {
    const int R = static_cast<int>(grid.size());
    const int C = static_cast<int>(grid[0].size());
    const int r = static_cast<int>(pattern.size());
    const int c = static_cast<int>(pattern[0].size());

    for (int i = 0; i <= R - r; ++i) {
        for (int j = 0; j <= C - c; ++j) {
            bool found = true;
            for (int k = 0; k < r; ++k) {
                if (grid[i + k].compare(j, c, pattern[k]) != 0) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return "YES";
            }
        }
    }
    return "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) {
        return 0;
    }

    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<string> grid(R);
        for (string &row : grid) {
            cin >> row;
        }

        int r, c;
        cin >> r >> c;
        vector<string> pattern(r);
        for (string &row : pattern) {
            cin >> row;
        }

        cout << gridSearch(grid, pattern) << '\n';
    }

    return 0;
}

