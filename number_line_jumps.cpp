#include <iostream>
#include <string>

std::string kangaroo(int x1, int v1, int x2, int v2) {
    if (v1 <= v2) {
        return (x1 == x2 && v1 == v2) ? "YES" : "NO";
    }
    return ((x2 - x1) % (v1 - v2) == 0) ? "YES" : "NO";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x1, v1, x2, v2;
    if (!(std::cin >> x1 >> v1 >> x2 >> v2)) {
        return 0;
    }

    std::cout << kangaroo(x1, v1, x2, v2) << '\n';
    return 0;
}

