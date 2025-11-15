#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int *ranked = malloc(sizeof(int) * n);
    if (!ranked) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &ranked[i]);
    }

    int *unique = malloc(sizeof(int) * n);
    if (!unique) {
        return 0;
    }

    int unique_count = 0;
    for (int i = 0; i < n; i++) {
        if (unique_count == 0 || ranked[i] != unique[unique_count - 1]) {
            unique[unique_count++] = ranked[i];
        }
    }

    int m;
    scanf("%d", &m);

    int *player = malloc(sizeof(int) * m);
    int *result = malloc(sizeof(int) * m);
    if (!player || !result) {

        return 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &player[i]);
    }

    int idx = unique_count - 1;
    for (int i = 0; i < m; i++) {
        while (idx >= 0 && player[i] >= unique[idx]) {
            idx--;
        }
        result[i] = idx + 2;
    }

    for (int i = 0; i < m; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}

