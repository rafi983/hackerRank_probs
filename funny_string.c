#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* funnyString(char* s) {
    int len = strlen(s);

    for (int i = 0; i < len - 1; i++) {
        int diff1 = abs(s[i] - s[i + 1]);
        int diff2 = abs(s[len - 1 - i] - s[len - 2 - i]);

        if (diff1 != diff2) {
            return "Not Funny";
        }
    }

    return "Funny";
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        char s[10001];
        scanf("%s", s);

        char* result = funnyString(s);
        printf("%s\n", result);
    }

    return 0;
}
