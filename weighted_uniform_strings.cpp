#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    if (!(std::cin >> s)) {
        return 0;
    }

    const std::size_t n = s.size();
    const std::size_t maxWeight = 26u * n + 5u;
    std::vector<bool> present(maxWeight, false);

    long long runLen = 0;
    int prev = 0;
    for (char ch : s) {
        if (runLen > 0 && ch == prev) {
            ++runLen;
        } else {
            runLen = 1;
        }
        const int w = (ch - 'a' + 1);
        const long long weight = static_cast<long long>(w) * runLen;
        if (weight >= 0 && static_cast<std::size_t>(weight) < maxWeight) {
            present[static_cast<std::size_t>(weight)] = true;
        }
        prev = ch;
    }

    int q;
    if (!(std::cin >> q)) {
        return 0;
    }

    while (q--) {
        long long x;
        std::cin >> x;
        if (x >= 0 && static_cast<std::size_t>(x) < maxWeight && present[static_cast<std::size_t>(x)]) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }

    return 0;
}

