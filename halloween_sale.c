#include <stdio.h>

static int howManyGames(int p, int d, int m, int s) {
    int count = 0;
    int price = p;
    while (s >= price) {
        s -= price;
        count++;
        int next = price - d;
        price = next > m ? next : m;
    }
    return count;
}

int main(void) {
    int p, d, m, s;
    if (scanf("%d %d %d %d", &p, &d, &m, &s) != 4) {
        return 0;
    }
    int result = howManyGames(p, d, m, s);
    printf("%d\n", result);
    return 0;
}

