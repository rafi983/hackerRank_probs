#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int M;
    if (!(std::cin >> M)) {
        return 0;
    }

    if (M % 3 == 0) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

    return 0;
}

