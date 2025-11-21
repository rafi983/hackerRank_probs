#include <iostream>
#include <vector>

static void countApplesAndOranges(int s, int t, int a, int b,
                                  const std::vector<int>& apples,
                                  const std::vector<int>& oranges) {
    int appleCount = 0;
    int orangeCount = 0;

    for (int d : apples) {
        const int position = a + d;
        if (position >= s && position <= t) {
            ++appleCount;
        }
    }

    for (int d : oranges) {
        const int position = b + d;
        if (position >= s && position <= t) {
            ++orangeCount;
        }
    }

    std::cout << appleCount << '\n' << orangeCount << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int s = 0, t = 0;
    int a = 0, b = 0;
    int m = 0, n = 0;

    if (!(std::cin >> s >> t >> a >> b >> m >> n)) {
        return 0;
    }

    std::vector<int> apples(m);
    std::vector<int> oranges(n);

    for (int& d : apples) {
        std::cin >> d;
    }
    for (int& d : oranges) {
        std::cin >> d;
    }

    countApplesAndOranges(s, t, a, b, apples, oranges);
    return 0;
}

