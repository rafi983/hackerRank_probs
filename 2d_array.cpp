#include <array>
#include <iostream>
#include <limits>

int main() {
    std::array<std::array<int, 6>, 6> grid{};
    for (auto &row : grid) {
        for (int &cell : row) {
            if (!(std::cin >> cell)) {
                return 0;
            }
        }
    }

    int maxSum = std::numeric_limits<int>::min();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            const int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2]
                           + grid[i + 1][j + 1]
                           + grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }

    std::cout << maxSum;
    return 0;
}

