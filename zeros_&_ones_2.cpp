#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    if (!(std::cin >> N) || N <= 0) {
        return 0;
    }

    std::vector<int> arr(N);
    for (int &value : arr) {
        std::cin >> value;
    }

    int X;
    if (!(std::cin >> X) || X < 1 || X > N) {
        return 0;
    }

    arr[X - 1] = arr[X - 1] == 0 ? 1 : 0;

    for (int i = 0; i < N; ++i) {
        if (i) {
            std::cout << ' ';
        }
        std::cout << arr[i];
    }
    std::cout << '\n';
    return 0;
}

