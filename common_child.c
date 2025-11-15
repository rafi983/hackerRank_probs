#include <stdio.h>
#include <string.h>

#define MAX_LEN 5000
#define STR_VALUE(x) #x
#define STR(x) STR_VALUE(x)

int main(void) {
    char s1[MAX_LEN + 2];
    char s2[MAX_LEN + 2];

    if (scanf("%" STR(MAX_LEN) "s", s1) != 1) {
        return 0;
    }
    if (scanf("%" STR(MAX_LEN) "s", s2) != 1) {
        return 0;
    }

    int len1 = (int)strlen(s1);
    int len2 = (int)strlen(s2);

    static int prev[MAX_LEN + 1];
    static int curr[MAX_LEN + 1];

    for (int i = 1; i <= len1; i++) {
        curr[0] = 0;
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                curr[j] = prev[j - 1] + 1;
            } else {
                curr[j] = curr[j - 1] > prev[j] ? curr[j - 1] : prev[j];
            }
        }
        memcpy(prev, curr, (size_t)(len2 + 1) * sizeof(int));
    }

    printf("%d\n", prev[len2]);
    return 0;
}
