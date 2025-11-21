#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    if (!(std::cin >> N)) {
        return 0;
    }

    for (int i = 1; i <= N; ++i) {
        for (int d = 1; d <= i; ++d) {
            std::cout << d;
        }
        if (i < N || N > 1) {
            std::cout << '\n';
        }
    }

    for (int i = N - 1; i >= 1; --i) {
        for (int s = 0; s < N - i; ++s) {
            std::cout << ' ';
        }
        for (int d = 1; d <= i; ++d) {
            std::cout << d;
        }
        if (i > 1) {
            std::cout << '\n';
        }
    }

    return 0;
}

