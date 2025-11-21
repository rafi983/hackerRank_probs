#include <iostream>
#include <string>

long long operationsToPalindrome(const std::string &s) {
    long long ops = 0;
    int i = 0;
    int j = static_cast<int>(s.size()) - 1;
    while (i < j) {
        ops += std::llabs(static_cast<long long>(s[i]) - static_cast<long long>(s[j]));
        ++i;
        --j;
    }
    return ops;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q;
    if (!(std::cin >> q)) {
        return 0;
    }

    while (q--) {
        std::string s;
        std::cin >> s;
        std::cout << operationsToPalindrome(s) << '\n';
    }

    return 0;
}

