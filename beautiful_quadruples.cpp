#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::array<int, 4> arr{};
    if (!(std::cin >> arr[0] >> arr[1] >> arr[2] >> arr[3])) {
        return 0;
    }

    std::sort(arr.begin(), arr.end());
    const int A = arr[0];
    const int B = arr[1];
    const int C = arr[2];
    const int D = arr[3];

    std::vector<long long> pre(B + 1);
    pre[0] = 0;
    for (int i = 1; i <= B; ++i) {
        pre[i] = pre[i - 1] + std::min(i, A);
    }

    long long total = 0;
    for (int cc = 1; cc <= C; ++cc) {
        const int mb = std::min(cc, B);
        const long long triple = pre[mb];
        total += triple * (D - cc + 1);
    }

    constexpr int maxX = 4096;
    std::vector<long long> cnt(maxX, 0);
    long long invalid = 0;

    for (int cc = 1; cc <= C; ++cc) {
        if (cc <= B) {
            const int limit = std::min(cc, A);
            for (int aa = 1; aa <= limit; ++aa) {
                ++cnt[aa ^ cc];
            }
        }
        for (int x = 0; x < maxX; ++x) {
            const int dd = x ^ cc;
            if (dd >= cc && dd <= D) {
                invalid += cnt[x];
            }
        }
    }

    const long long result = total - invalid;
    std::cout << result << '\n';
    return 0;
}

