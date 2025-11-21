#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> allocGrid(int r, int c) {
    return vector<string>(r, string(c, '.'));
}

void fillFull(vector<string> &grid) {
    for (auto &row : grid) {
        row.assign(row.size(), 'O');
    }
}

vector<string> explode(const vector<string> &source) {
    const int r = static_cast<int>(source.size());
    const int c = static_cast<int>(source[0].size());
    vector<string> dest = allocGrid(r, c);
    fillFull(dest);

    auto clearCell = [&](int i, int j) {
        if (i >= 0 && i < r && j >= 0 && j < c) {
            dest[i][j] = '.';
        }
    };

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (source[i][j] == 'O') {
                clearCell(i, j);
                clearCell(i - 1, j);
                clearCell(i + 1, j);
                clearCell(i, j - 1);
                clearCell(i, j + 1);
            }
        }
    }

    return dest;
}

void printGrid(const vector<string> &grid) {
    for (const auto &row : grid) {
        cout << row << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    long long n;
    if (!(cin >> r >> c >> n)) {
        return 0;
    }

    vector<string> initial(r);
    for (string &row : initial) {
        cin >> row;
    }

    if (n == 1) {
        printGrid(initial);
        return 0;
    }

    if (n % 2 == 0) {
        vector<string> full = allocGrid(r, c);
        fillFull(full);
        printGrid(full);
        return 0;
    }

    vector<string> state1 = explode(initial);
    vector<string> state2 = explode(state1);

    const vector<string> &result = (n % 4 == 3) ? state1 : state2;
    printGrid(result);
    return 0;
}

