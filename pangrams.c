#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char* pangrams(char* s) {
    bool letters[26] = {false};
    int len = strlen(s);
    int uniqueCount = 0;

    for (int i = 0; i < len; i++) {
        if (isalpha(s[i])) {
            char ch = tolower(s[i]);
            int index = ch - 'a';

            if (!letters[index]) {
                letters[index] = true;
                uniqueCount++;

                if (uniqueCount == 26) {
                    return "pangram";
                }
            }
        }
    }

    return "not pangram";
}

int main() {
    char s[1001];
    fgets(s, sizeof(s), stdin);

    s[strcspn(s, "\n")] = '\0';

    char* result = pangrams(s);
    printf("%s\n", result);

    return 0;
}
