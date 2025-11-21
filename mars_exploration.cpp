#include <iostream>
#include <string>

int marsExploration(const std::string &s) {
    static constexpr char pattern[3] = {'S', 'O', 'S'};
    int changedCount = 0;
    const int len = static_cast<int>(s.size());

    for (int i = 0; i < len; ++i) {
        if (s[i] != pattern[i % 3]) {
            ++changedCount;
        }
    }

    return changedCount;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    if (!(std::cin >> s)) {
        return 0;
    }

    std::cout << marsExploration(s) << '\n';
    return 0;
}

