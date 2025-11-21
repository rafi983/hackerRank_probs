#include <iostream>
#include <string>

static int alternatingCharacters(const std::string& s) {
    int deletions = 0;
    for (std::size_t i = 0; i + 1 < s.size(); ++i) {
        if (s[i] == s[i + 1]) {
            ++deletions;
        }
    }
    return deletions;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q = 0;
    if (!(std::cin >> q)) {
        return 0;
    }

    while (q--) {
        std::string s;
        std::cin >> s;
        std::cout << alternatingCharacters(s) << '\n';
    }

    return 0;
}

