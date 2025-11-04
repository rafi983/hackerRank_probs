#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int minimumNumber(int n, char* password) {
    bool hasDigit = false;
    bool hasLower = false;
    bool hasUpper = false;
    bool hasSpecial = false;

    char special[] = "!@#$%^&*()-+";

    for (int i = 0; i < n; i++) {
        char ch = password[i];

        if (isdigit(ch)) {
            hasDigit = true;
        } else if (islower(ch)) {
            hasLower = true;
        } else if (isupper(ch)) {
            hasUpper = true;
        } else if (strchr(special, ch) != NULL) {
            hasSpecial = true;
        }
    }

    int missingTypes = 0;
    if (!hasDigit) missingTypes++;
    if (!hasLower) missingTypes++;
    if (!hasUpper) missingTypes++;
    if (!hasSpecial) missingTypes++;

    int lengthNeeded = 0;
    if (n < 6) {
        lengthNeeded = 6 - n;
    }

    return (missingTypes > lengthNeeded) ? missingTypes : lengthNeeded;
}

int main() {
    int n;
    char password[101];

    scanf("%d", &n);
    scanf("%s", password);

    int result = minimumNumber(n, password);
    printf("%d\n", result);

    return 0;
}

