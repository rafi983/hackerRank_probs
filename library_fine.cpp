#include <iostream>

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
    if (y1 > y2) {
        return 10000;
    }
    if (y1 < y2) {
        return 0;
    }
    if (m1 > m2) {
        return 500 * (m1 - m2);
    }
    if (m1 < m2) {
        return 0;
    }
    if (d1 > d2) {
        return 15 * (d1 - d2);
    }
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int d1, m1, y1;
    int d2, m2, y2;
    if (!(std::cin >> d1 >> m1 >> y1)) {
        return 0;
    }
    if (!(std::cin >> d2 >> m2 >> y2)) {
        return 0;
    }

    std::cout << libraryFine(d1, m1, y1, d2, m2, y2) << '\n';
    return 0;
}

