#include <iostream>

int utopianTree(int n) {
    int height = 1;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 1) {
            height *= 2;
        } else {
            height += 1;
        }
    }
    return height;
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
        std::cout << utopianTree(n) << '\n';
    }
    return 0;
}

