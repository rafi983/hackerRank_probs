#include <iostream>
#include <vector>
#include <array>

int equalizeArray(const std::vector<int> &arr) {
    std::array<int, 101> count = {0};
    for (int value : arr) {
        ++count[value];
    }

    int max_frequency = 0;
    for (int freq : count) {
        if (freq > max_frequency) {
            max_frequency = freq;
        }
    }

    return static_cast<int>(arr.size()) - max_frequency;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::vector<int> arr(n);
    for (int &value : arr) {
        std::cin >> value;
    }

    std::cout << equalizeArray(arr) << '\n';
    return 0;
}

