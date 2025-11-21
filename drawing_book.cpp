#include <iostream>

int pageCount(int n, int p) {
    const int turns_from_front = p / 2;
    const int turns_from_back = (n / 2) - (p / 2);
    return turns_from_front < turns_from_back ? turns_from_front : turns_from_back;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, p;
    if (!(std::cin >> n >> p)) {
        return 0;
    }

    std::cout << pageCount(n, p) << '\n';
    return 0;
}

