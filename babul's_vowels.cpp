#include <iostream>

int main() {
    char c;
    if (!(std::cin >> c)) {
        return 0;
    }

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        std::cout << "Vowel\n";
    } else {
        std::cout << "Consonant\n";
    }

    return 0;
}

