#include <iostream>
#include <vector>

static void bonAppetit(const std::vector<int>& bill, int k, int b) {
    int total = 0;
    for (int i = 0; i < static_cast<int>(bill.size()); ++i) {
        if (i != k) {
            total += bill[i];
        }
    }

    const int fairShare = total / 2;
    if (fairShare == b) {
        std::cout << "Bon Appetit\n";
    } else {
        std::cout << (b - fairShare) << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    int k = 0;
    if (!(std::cin >> n >> k)) {
        return 0;
    }

    std::vector<int> bill(n);
    for (int& cost : bill) {
        std::cin >> cost;
    }

    int b = 0;
    std::cin >> b;

    bonAppetit(bill, k, b);
    return 0;
}

