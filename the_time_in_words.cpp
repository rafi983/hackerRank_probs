#include <iostream>
#include <array>
#include <string>

namespace {
constexpr std::array<const char *, 30> kNumWords = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
    "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine"
};

inline const char *word(int n) {
    return kNumWords[n];
}

std::string timeInWords(int h, int m) {
    if (m == 0) {
        return std::string(word(h)) + " o' clock";
    }
    if (m == 15) {
        return std::string("quarter past ") + word(h);
    }
    if (m == 30) {
        return std::string("half past ") + word(h);
    }
    if (m == 45) {
        const int nextHour = h == 12 ? 1 : h + 1;
        return std::string("quarter to ") + word(nextHour);
    }
    if (m < 30) {
        if (m == 1) {
            return std::string("one minute past ") + word(h);
        }
        return std::string(word(m)) + " minutes past " + word(h);
    }

    const int remaining = 60 - m;
    const int nextHour = h == 12 ? 1 : h + 1;
    if (remaining == 1) {
        return std::string("one minute to ") + word(nextHour);
    }
    return std::string(word(remaining)) + " minutes to " + word(nextHour);
}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int h, m;
    if (!(std::cin >> h >> m)) {
        return 0;
    }

    std::cout << timeInWords(h, m) << '\n';
    return 0;
}

