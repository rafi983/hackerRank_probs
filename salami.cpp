#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int X = 0;
    int Y = 0;
    int Z = 0;
    if (!(std::cin >> X >> Y >> Z)) {
        return 0;
    }

    const int total = X + Y + Z;
    std::cout << total << '\n';
    return 0;
}
