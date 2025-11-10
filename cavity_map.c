#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cavityMap(int n, char** grid) {
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            char current = grid[i][j];
            if (current > grid[i - 1][j] &&
                current > grid[i + 1][j] &&
                current > grid[i][j - 1] &&
                current > grid[i][j + 1]) {

            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char** grid = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        grid[i] = (char*)malloc((n + 1) * sizeof(char));
        scanf("%s", grid[i]);
    }

    char** result = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        result[i] = (char*)malloc((n + 1) * sizeof(char));
        strcpy(result[i], grid[i]);
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            char current = grid[i][j];
            char up = grid[i - 1][j];
            char down = grid[i + 1][j];
            char left = grid[i][j - 1];
            char right = grid[i][j + 1];

            if (current > up && current > down && current > left && current > right) {
                result[i][j] = 'X';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", result[i]);
    }

    for (int i = 0; i < n; i++) {
        free(grid[i]);
        free(result[i]);
    }
    free(grid);
    free(result);

    return 0;
}

