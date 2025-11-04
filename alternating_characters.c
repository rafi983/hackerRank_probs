#include <stdio.h>
#include <string.h>

int alternatingCharacters(char* s) {
    int deletions = 0;
    int len = strlen(s);

    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            deletions++;
        }
    }

    return deletions;
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        char s[100001];
        scanf("%s", s);

        int result = alternatingCharacters(s);
        printf("%d\n", result);
    }

    return 0;
}
