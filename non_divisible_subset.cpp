#include <iostream>
#include <vector>
#include <algorithm>

namespace {
inline int maxInt(int a, int b) {
    return a > b ? a : b;
}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    int k = 0;
    if (!(std::cin >> n >> k) || k <= 0 || n <= 0) {
        return 0;
    }

    std::vector<int> freq(k, 0);
    for (int i = 0; i < n; ++i) {
        int value = 0;
        if (!(std::cin >> value)) {
            return 0;
        }
        int rem = value % k;
        if (rem < 0) {
            rem += k;
        }
        ++freq[rem];
    }

    int result = 0;
    if (freq[0] > 0) {
        ++result;
    }

    for (int r = 1; r <= k / 2; ++r) {
        if (r == k - r) {
            if (freq[r] > 0) {
                ++result;
            }
        } else {
            result += maxInt(freq[r], freq[k - r]);
        }
    }

    std::cout << result << '\n';
    return 0;
}

