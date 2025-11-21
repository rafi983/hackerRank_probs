#include <iostream>
#include <vector>
#include <array>

int pickingNumbers(const std::vector<int> &a) {
    std::array<int, 101> freq{};
    for (int value : a) {
        ++freq[value];
    }

    int maxLength = 0;
    for (int i = 1; i < 100; ++i) {
        const int currentLength = freq[i] + freq[i + 1];
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    return maxLength;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::vector<int> a(n);
    for (int &value : a) {
        std::cin >> value;
    }

    std::cout << pickingNumbers(a) << '\n';
    return 0;
}

