#include <iostream>
#include <vector>
#include <algorithm>

int hurdleRace(int k, const std::vector<int> &height) {
    const int max_height = *std::max_element(height.begin(), height.end());
    const int diff = max_height - k;
    return diff > 0 ? diff : 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    if (!(std::cin >> n >> k)) {
        return 0;
    }

    std::vector<int> height(n, 0);
    for (int &value : height) {
        if (!(std::cin >> value)) {
            value = 0;
        }
    }

    if (n == 0) {
        std::cout << 0 << '\n';
        return 0;
    }

    std::cout << hurdleRace(k, height) << '\n';
    return 0;
}

