#include <iostream>
#include <string>
#include <vector>

static std::string angryProfessor(int k, const std::vector<int>& arrivals) {
    int onTime = 0;
    for (int time : arrivals) {
        if (time <= 0) {
            ++onTime;
        }
    }
    return (onTime >= k) ? "NO" : "YES";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    if (!(std::cin >> t)) {
        return 0;
    }

    while (t--) {
        int n = 0;
        int k = 0;
        std::cin >> n >> k;

        std::vector<int> arrivals(n);
        for (int& time : arrivals) {
            std::cin >> time;
        }

        std::cout << angryProfessor(k, arrivals) << '\n';
    }

    return 0;
}

