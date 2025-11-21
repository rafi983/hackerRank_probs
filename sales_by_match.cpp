#include <iostream>
#include <vector>

int sockMerchant(const std::vector<int> &ar) {
    int color_count[101] = {0};
    for (int value : ar) {
        ++color_count[value];
    }

    int total_pairs = 0;
    for (int i = 1; i <= 100; ++i) {
        total_pairs += color_count[i] / 2;
    }
    return total_pairs;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::vector<int> ar(n);
    for (int &value : ar) {
        std::cin >> value;
    }

    std::cout << sockMerchant(ar) << '\n';
    return 0;
}

