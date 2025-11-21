#include <iostream>
#include <vector>

int jumpingOnClouds(const std::vector<int> &clouds) {
    int jumps = 0;
    int i = 0;
    const int n = static_cast<int>(clouds.size());

    while (i < n - 1) {
        if (i + 2 < n && clouds[i + 2] == 0) {
            i += 2;
        } else {
            ++i;
        }
        ++jumps;
    }

    return jumps;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::vector<int> clouds(n);
    for (int &cloud : clouds) {
        std::cin >> cloud;
    }

    std::cout << jumpingOnClouds(clouds) << '\n';
    return 0;
}

