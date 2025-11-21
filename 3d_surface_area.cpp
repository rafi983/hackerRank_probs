#include <algorithm>
#include <iostream>
#include <vector>

static long long compute_surface_area(const std::vector<std::vector<int>>& grid) {
    const int H = static_cast<int>(grid.size());
    const int W = H ? static_cast<int>(grid.front().size()) : 0;
    long long total = 0;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] > 0) {
                total += 2LL + 4LL * grid[i][j];
            }
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j + 1 < W; ++j) {
            total -= 2LL * std::min(grid[i][j], grid[i][j + 1]);
        }
    }

    for (int i = 0; i + 1 < H; ++i) {
        for (int j = 0; j < W; ++j) {
            total -= 2LL * std::min(grid[i][j], grid[i + 1][j]);
        }
    }

    return total;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W;
    if (!(std::cin >> H >> W)) {
        return 0;
    }

    std::vector<std::vector<int>> grid(H, std::vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            std::cin >> grid[i][j];
        }
    }

    std::cout << compute_surface_area(grid) << '\n';
    return 0;
}

