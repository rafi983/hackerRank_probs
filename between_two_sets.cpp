#include <iostream>
#include <numeric>
#include <vector>

static int lcm_pair(int a, int b) {
    return (a / std::gcd(a, b)) * b;
}

static int lcm_of_array(const std::vector<int>& arr) {
    int result = arr.front();
    for (std::size_t i = 1; i < arr.size(); ++i) {
        result = lcm_pair(result, arr[i]);
    }
    return result;
}

static int gcd_of_array(const std::vector<int>& arr) {
    int result = arr.front();
    for (std::size_t i = 1; i < arr.size(); ++i) {
        result = std::gcd(result, arr[i]);
    }
    return result;
}

static int getTotalX(const std::vector<int>& a, const std::vector<int>& b) {
    const int lcmA = lcm_of_array(a);
    const int gcdB = gcd_of_array(b);

    int count = 0;
    for (int x = lcmA; x <= gcdB; x += lcmA) {
        if (gcdB % x == 0) {
            ++count;
        }
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    int m = 0;
    if (!(std::cin >> n >> m)) {
        return 0;
    }

    std::vector<int> a(n);
    std::vector<int> b(m);

    for (int& value : a) {
        std::cin >> value;
    }
    for (int& value : b) {
        std::cin >> value;
    }

    std::cout << getTotalX(a, b) << '\n';
    return 0;
}

