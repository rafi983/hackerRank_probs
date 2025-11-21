#include <iostream>
#include <vector>

int birthday(const std::vector<int> &s, int d, int m) {
    int count = 0;
    const int n = static_cast<int>(s.size());

    for (int i = 0; i <= n - m; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += s[i + j];
        }
        if (sum == d) {
            ++count;
        }
    }

    return count;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::vector<int> s(n);
    for (int &value : s) {
        std::cin >> value;
    }

    int d, m;
    std::cin >> d >> m;

    std::cout << birthday(s, d, m) << '\n';
    return 0;
}

