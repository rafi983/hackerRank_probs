#include <iostream>
#include <string>
#include <vector>

int maxAlternatingTwoChars(const std::string &s) {
    bool present[26] = {false};
    const int n = static_cast<int>(s.size());
    for (char ch : s) {
        if (ch >= 'a' && ch <= 'z') {
            present[ch - 'a'] = true;
        }
    }

    int best = 0;
    for (int a = 0; a < 26; ++a) {
        if (!present[a]) continue;
        for (int b = a + 1; b < 26; ++b) {
            if (!present[b]) continue;

            const char ca = static_cast<char>('a' + a);
            const char cb = static_cast<char>('a' + b);
            char prev = 0;
            int len = 0;
            int countA = 0;
            int countB = 0;
            bool ok = true;

            for (char ch : s) {
                if (ch != ca && ch != cb) continue;
                if (prev == ch) {
                    ok = false;
                    break;
                }
                prev = ch;
                ++len;
                if (ch == ca) {
                    ++countA;
                } else {
                    ++countB;
                }
            }

            if (ok && countA > 0 && countB > 0 && len > best) {
                best = len;
            }
        }
    }

    return best;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::string s;
    std::cin >> s;

    std::cout << maxAlternatingTwoChars(s) << '\n';
    return 0;
}

