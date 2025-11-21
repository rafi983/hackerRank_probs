#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int M;
    if (!(std::cin >> M)) {
        return 0;
    }

    if (M >= 1000) {
        std::cout << "Three Kacchi\n";
    } else if (M >= 500) {
        std::cout << "One Large Pizza\n";
    } else if (M >= 250) {
        std::cout << "Three Small Burger\n";
    } else if (M >= 100) {
        std::cout << "Three Fuchka\n";
    } else {
        std::cout << "Nothing\n";
    }

    return 0;
}

