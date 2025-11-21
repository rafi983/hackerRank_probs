#include <iostream>
#include <vector>
#include <array>

using namespace std;

namespace {
constexpr int MAX_EXPENDITURE = 200;

int findTwiceMedian(const array<int, MAX_EXPENDITURE + 1> &counts, int d) {
    const int target1 = (d + 1) / 2;
    const int target2 = (d % 2 == 0) ? (target1 + 1) : target1;

    int cumulative = 0;
    int firstValue = 0;
    int secondValue = 0;
    bool firstFound = false;
    bool secondFound = false;

    for (int value = 0; value <= MAX_EXPENDITURE; ++value) {
        cumulative += counts[value];
        if (!firstFound && cumulative >= target1) {
            firstValue = value;
            firstFound = true;
        }
        if (!secondFound && cumulative >= target2) {
            secondValue = value;
            secondFound = true;
            break;
        }
    }

    return firstValue + secondValue;
}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    int d = 0;
    if (!(cin >> n >> d) || n <= 0 || d <= 0 || d > n) {
        return 0;
    }

    vector<int> expenditure(n);
    for (int &value : expenditure) {
        if (!(cin >> value)) {
            return 0;
        }
    }

    array<int, MAX_EXPENDITURE + 1> counts{};
    for (int i = 0; i < d; ++i) {
        ++counts[expenditure[i]];
    }

    int notifications = 0;
    for (int i = d; i < n; ++i) {
        const int twiceMedian = findTwiceMedian(counts, d);
        if (expenditure[i] >= twiceMedian) {
            ++notifications;
        }
        --counts[expenditure[i - d]];
        ++counts[expenditure[i]];
    }

    cout << notifications << '\n';
    return 0;
}

