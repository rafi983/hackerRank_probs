#include <iostream>
#include <array>

namespace {
constexpr int kMaxDigits = 200;

struct BigInteger {
    std::array<int, kMaxDigits> digits{};
    int length = 1;
};

void initBigInteger(BigInteger &num) {
    num.digits.fill(0);
    num.length = 1;
}

void multiplyByInt(BigInteger &num, int multiplier) {
    int carry = 0;
    for (int i = 0; i < num.length; ++i) {
        const int product = num.digits[i] * multiplier + carry;
        num.digits[i] = product % 10;
        carry = product / 10;
    }
    while (carry > 0) {
        num.digits[num.length] = carry % 10;
        carry /= 10;
        ++num.length;
    }
}

void printBigInteger(const BigInteger &num) {
    for (int i = num.length - 1; i >= 0; --i) {
        std::cout << num.digits[i];
    }
    std::cout << '\n';
}

void extraLongFactorials(int n) {
    BigInteger result;
    initBigInteger(result);
    result.digits[0] = 1;

    for (int i = 2; i <= n; ++i) {
        multiplyByInt(result, i);
    }

    printBigInteger(result);
}
}  // namespace

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    extraLongFactorials(n);
    return 0;
}

