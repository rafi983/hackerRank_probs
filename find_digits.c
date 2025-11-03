#include <stdio.h>

int findDigits(int n) {
    int temp = n;
    int count = 0;

    while (temp > 0) {
        int digit = temp % 10;
        if (digit != 0 && n % digit == 0) {
            count++;
        }
        temp /= 10;
    }

    return count;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        int result = findDigits(n);
        printf("%d\n", result);
    }

    return 0;
}
