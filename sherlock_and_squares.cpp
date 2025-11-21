#include <iostream>
#include <cmath>

int squares(int a, int b) {
    int sqrt_a = static_cast<int>(std::ceil(std::sqrt(a)));
    int sqrt_b = static_cast<int>(std::floor(std::sqrt(b)));

    if (sqrt_a > sqrt_b) {
        return 0;
    }

    return sqrt_b - sqrt_a + 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q;
    if (!(std::cin >> q)) {
        return 0;
    }

    while (q--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << squares(a, b) << '\n';
    }

    return 0;
}

