#include <iostream>
#include <string>

static void reverse_suffix(std::string& s, int start, int end) {
    while (start < end) {
        std::swap(s[start], s[end]);
        ++start;
        --end;
    }
}

static bool next_greater_word(std::string& s) {
    const int len = static_cast<int>(s.size());
    if (len <= 1) {
        return false;
    }

    int pivot = len - 2;
    while (pivot >= 0 && s[pivot] >= s[pivot + 1]) {
        --pivot;
    }
    if (pivot < 0) {
        return false;
    }

    int successor = len - 1;
    while (successor > pivot && s[successor] <= s[pivot]) {
        --successor;
    }

    std::swap(s[pivot], s[successor]);
    reverse_suffix(s, pivot + 1, len - 1);
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    if (!(std::cin >> t)) {
        return 0;
    }

    std::string word;
    word.reserve(100000);

    while (t--) {
        if (!(std::cin >> word)) {
            return 0;
        }
        if (next_greater_word(word)) {
            std::cout << word << '\n';
        } else {
            std::cout << "no answer\n";
        }
    }

    return 0;
}

