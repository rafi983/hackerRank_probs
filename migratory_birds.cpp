#include <iostream>
#include <vector>

int migratoryBirds(const std::vector<int> &arr) {
    int count[6] = {0};
    for (int value : arr) {
        ++count[value];
    }

    int maxCount = 0;
    int resultType = 1;
    for (int type = 1; type <= 5; ++type) {
        if (count[type] > maxCount) {
            maxCount = count[type];
            resultType = type;
        }
    }
    return resultType;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::vector<int> arr(n);
    for (int &value : arr) {
        std::cin >> value;
    }

    std::cout << migratoryBirds(arr) << '\n';
    return 0;
}

