#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* superReducedString(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (top >= 0 && result[top] == s[i]) {
            top--;
        } else {
            top++;
            result[top] = s[i];
        }
    }

    if (top == -1) {
        strcpy(result, "Empty String");
    } else {
        result[top + 1] = '\0';
    }

    return result;
}

int main() {
    char s[101];
    scanf("%s", s);

    char* result = superReducedString(s);
    printf("%s\n", result);

    free(result);
    return 0;
}
