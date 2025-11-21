#include <array>
#include <iostream>
#include <string>

static int anagram(const std::string& s) {
    const int len = static_cast<int>(s.size());
    if (len % 2 == 1) {
        return -1;
    }

    const int mid = len / 2;
    std::array<int, 26> freq1{};
    std::array<int, 26> freq2{};

    for (int i = 0; i < mid; ++i) {
        ++freq1[s[i] - 'a'];
        ++freq2[s[mid + i] - 'a'];
    }

    int changes = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq1[i] > freq2[i]) {
            changes += freq1[i] - freq2[i];
        }
    }

    return changes;
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
        std::cout << anagram(s) << '\n';
    }

    return 0;
}

