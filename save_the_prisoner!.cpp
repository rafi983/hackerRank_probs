#include <iostream>

int saveThePrisoner(int n, int m, int s) {
    return ((s - 1) + (m - 1)) % n + 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t)) {
        return 0;
    }

    while (t--) {
        int n, m, s;
        std::cin >> n >> m >> s;
        std::cout << saveThePrisoner(n, m, s) << '\n';
    }

    return 0;
}

