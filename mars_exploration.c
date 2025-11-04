#include <stdio.h>
#include <string.h>

int marsExploration(char* s) {
    char pattern[] = "SOS";
    int changedCount = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (s[i] != pattern[i % 3]) {
            changedCount++;
        }
    }

    return changedCount;
}

int main() {
    char s[101];

    scanf("%s", s);

    int result = marsExploration(s);
    printf("%d\n", result);

    return 0;
}

