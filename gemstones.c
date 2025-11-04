#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int gemstones(char arr[][101], int n) {
    int gemstoneCount = 0;

    for (char mineral = 'a'; mineral <= 'z'; mineral++) {
        bool isGemstone = true;

        for (int i = 0; i < n; i++) {
            if (strchr(arr[i], mineral) == NULL) {
                isGemstone = false;
                break;
            }
        }

        if (isGemstone) {
            gemstoneCount++;
        }
    }

    return gemstoneCount;
}

int main() {
    int n;
    scanf("%d", &n);

    char arr[100][101];
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    int result = gemstones(arr, n);
    printf("%d\n", result);

    return 0;
}
