#include <iostream>
#include <vector>

static int beautifulTriplets(int d, const std::vector<int>& arr) {
    const int n = static_cast<int>(arr.size());
    int count = 0;

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            const int diff1 = arr[j] - arr[i];
            if (diff1 == d) {
                for (int k = j + 1; k < n; ++k) {
                    const int diff2 = arr[k] - arr[j];
                    if (diff2 == d) {
                        ++count;
                    }
                    if (diff2 > d) {
                        break;
                    }
                }
            }
            if (diff1 > d) {
                break;
            }
        }
    }

    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    int d = 0;
    if (!(std::cin >> n >> d)) {
        return 0;
    }

    std::vector<int> arr(n);
    for (int& value : arr) {
        std::cin >> value;
    }

    std::cout << beautifulTriplets(d, arr) << '\n';
    return 0;
}

