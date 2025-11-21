#include <iostream>
#include <string>

int main() {
    int n = 0;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::string b;
    b.reserve(n);
    if (!(std::cin >> b)) {
        return 0;
    }

    int changes = 0;
    for (int i = 0; i + 2 < n;) {
        if (b[i] == '0' && b[i + 1] == '1' && b[i + 2] == '0') {
            ++changes;
            i += 3;
        } else {
            ++i;
        }
    }

    std::cout << changes << '\n';
    return 0;
}

