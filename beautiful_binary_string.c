#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    char *b = (char *)malloc((size_t)n + 5u);
    if (!b) return 1;

    if (scanf("%s", b) != 1) {
        free(b);
        return 0;
    }

    int changes = 0;
    for (int i = 0; i + 2 < n; ) {
        if (b[i] == '0' && b[i+1] == '1' && b[i+2] == '0') {
            changes++;
            i += 3;
        } else {
            i++;
        }
    }

    printf("%d\n", changes);
    free(b);
    return 0;
}

