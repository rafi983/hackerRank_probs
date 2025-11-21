#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    long long k;
    if (!(std::cin >> n >> k) || n <= 0) {
        return 0;
    }

    std::vector<long long> a(n);
    for (long long &value : a) {
        std::cin >> value;
    }

    std::sort(a.begin(), a.end());

    int count = 0;
    int i = 0;
    int j = 1;

    while (j < n) {
        long long diff = a[j] - a[i];
        if (diff == k) {
            ++count;
            ++i;
            ++j;
        } else if (diff < k) {
            ++j;
        } else {
            ++i;
            if (i == j) {
                ++j;
            }
        }
    }

    std::cout << count;
    return 0;
}

