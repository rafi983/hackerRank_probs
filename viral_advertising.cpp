#include <iostream>

int viralAdvertising(int n) {
    int shared = 5;
    int cumulativeLikes = 0;

    for (int day = 1; day <= n; ++day) {
        const int liked = shared / 2;
        cumulativeLikes += liked;
        shared = liked * 3;
    }

    return cumulativeLikes;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::cout << viralAdvertising(n) << '\n';
    return 0;
}

