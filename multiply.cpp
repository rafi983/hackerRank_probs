#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long A;
    long long B;
    if (!(std::cin >> A >> B)) {
        return 0;
    }

    const long long result = A * B;
    std::cout << result << '\n';
    return 0;
}

