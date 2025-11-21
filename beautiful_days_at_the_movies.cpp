#include <cstdlib>
#include <iostream>

static long long reverse_number(long long x) {
    long long rev = 0;
    while (x > 0) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    return rev;
}

static int beautifulDays(long long i, long long j, long long k) {
    int count = 0;
    for (long long day = i; day <= j; ++day) {
        const long long rev = reverse_number(day);
        const long long diff = std::llabs(day - rev);
        if (diff % k == 0) {
            ++count;
        }
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long i = 0, j = 0, k = 0;
    if (!(std::cin >> i >> j >> k)) {
        return 0;
    }

    std::cout << beautifulDays(i, j, k) << '\n';
    return 0;
}

