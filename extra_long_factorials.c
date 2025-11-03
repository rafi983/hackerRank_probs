#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 200

typedef struct {
    int digits[MAX_DIGITS];
    int length;
} BigInteger;

void initBigInteger(BigInteger* num) {
    memset(num->digits, 0, sizeof(num->digits));
    num->length = 1;
}

void multiplyByInt(BigInteger* num, int multiplier) {
    int carry = 0;

    for (int i = 0; i < num->length; i++) {
        int product = num->digits[i] * multiplier + carry;
        num->digits[i] = product % 10;
        carry = product / 10;
    }

    while (carry > 0) {
        num->digits[num->length] = carry % 10;
        carry = carry / 10;
        num->length++;
    }
}

void printBigInteger(BigInteger* num) {
    for (int i = num->length - 1; i >= 0; i--) {
        printf("%d", num->digits[i]);
    }
    printf("\n");
}

void extraLongFactorials(int n) {
    BigInteger result;
    initBigInteger(&result);
    result.digits[0] = 1;

    for (int i = 2; i <= n; i++) {
        multiplyByInt(&result, i);
    }

    printBigInteger(&result);
}

int main() {
    int n;
    scanf("%d", &n);
    extraLongFactorials(n);
    return 0;
}
