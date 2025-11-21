#include <iostream>
#include <vector>

int lonelyinteger(const std::vector<int> &a) {
    int result = 0;
    for (int value : a) {
        result ^= value;
    }
    return result;
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

    std::cout << lonelyinteger(a) << '\n';
    return 0;
}

