#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n) || n <= 0) {
        return 0;
    }

    std::vector<int> arr(n);
    for (int &value : arr) {
        std::cin >> value;
    }

    const int maxVal = *std::max_element(arr.begin(), arr.end());

    for (int i = 0; i < n; ++i) {
        if (i) {
            std::cout << ' ';
        }
        std::cout << (maxVal - arr[i]);
    }
    std::cout << '\n';

    return 0;
}

