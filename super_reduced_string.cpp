#include <iostream>
#include <string>

std::string superReducedString(const std::string &s) {
    std::string result;
    result.reserve(s.size());

    for (char ch : s) {
        if (!result.empty() && result.back() == ch) {
            result.pop_back();
        } else {
            result.push_back(ch);
        }
    }

    if (result.empty()) {
        return "Empty String";
    }
    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    if (!(std::cin >> s)) {
        return 0;
    }

    std::cout << superReducedString(s) << '\n';
    return 0;
}

