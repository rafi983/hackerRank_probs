#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    if (!(std::cin >> N)) {
        return 0;
    }

    for (int i = 1; i <= N; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            std::cout << i << " Yes\n";
        } else {
            std::cout << i << " No\n";
        }
    }

    return 0;
}

