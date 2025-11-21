#include <iostream>

int findDigits(int n) {
    int temp = n;
    int count = 0;

    while (temp > 0) {
        int digit = temp % 10;
        if (digit != 0 && n % digit == 0) {
            ++count;
        }
        temp /= 10;
    }

    return count;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t)) {
        return 0;
    }

    while (t--) {
        int n;
        std::cin >> n;
        std::cout << findDigits(n) << '\n';
    }

    return 0;
}

