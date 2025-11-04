#include <stdio.h>
#include <string.h>

char* gameOfThrones(char* s) {
    int freq[26] = {0};
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }

    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            oddCount++;
            if (oddCount > 1) {
                return "NO";
            }
        }
    }

    return "YES";
}

int main() {
    char s[100001];
    scanf("%s", s);

    char* result = gameOfThrones(s);
    printf("%s\n", result);

    return 0;
}
