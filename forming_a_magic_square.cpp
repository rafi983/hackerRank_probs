#include <iostream>
#include <array>
#include <climits>

using namespace std;

constexpr array<array<array<int, 3>, 3>, 8> kMagicSquares = { {
    {{{8, 1, 6}, {3, 5, 7}, {4, 9, 2}}},
    {{{6, 1, 8}, {7, 5, 3}, {2, 9, 4}}},
    {{{4, 9, 2}, {3, 5, 7}, {8, 1, 6}}},
    {{{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}},
    {{{8, 3, 4}, {1, 5, 9}, {6, 7, 2}}},
    {{{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}},
    {{{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}},
    {{{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}}
} };

int formingMagicSquare(const array<array<int, 3>, 3> &square) {
    int minCost = INT_MAX;
    for (const auto &magic : kMagicSquares) {
        int currentCost = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                currentCost += abs(square[i][j] - magic[i][j]);
            }
        }
        if (currentCost < minCost) {
            minCost = currentCost;
        }
    }
    return minCost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<array<int, 3>, 3> square{};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!(cin >> square[i][j])) {
                return 0;
            }
        }
    }

    cout << formingMagicSquare(square) << '\n';
    return 0;
}

