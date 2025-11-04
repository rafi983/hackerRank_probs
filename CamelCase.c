#include <stdio.h>
#include <string.h>
#include <ctype.h>


int camelcase(char* s) {
    int wordCount = 1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isupper(s[i])) {
            wordCount++;
        }
    }

    return wordCount;
}

int main() {
    char s[100001];

    scanf("%s", s);

    int result = camelcase(s);
    printf("%d\n", result);

    return 0;
}

