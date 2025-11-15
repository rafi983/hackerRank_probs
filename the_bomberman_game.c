#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char **alloc_grid(int r, int c) {
    char **grid = malloc((size_t)r * sizeof(char *));
    if (!grid) {
        return NULL;
    }
    for (int i = 0; i < r; i++) {
        grid[i] = malloc((size_t)c + 1);
        if (!grid[i]) {
            for (int j = 0; j < i; j++) {
                free(grid[j]);
            }
            free(grid);
            return NULL;
        }
    }
    return grid;
}

static void free_grid(char **grid, int r) {
    if (!grid) {
        return;
    }
    for (int i = 0; i < r; i++) {
        free(grid[i]);
    }
    free(grid);
}

static void fill_full(char **grid, int r, int c) {
    for (int i = 0; i < r; i++) {
        memset(grid[i], 'O', (size_t)c);
        grid[i][c] = '\0';
    }
}

static void explode(char **source, char **dest, int r, int c) {
    fill_full(dest, r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (source[i][j] == 'O') {
                dest[i][j] = '.';
                if (i > 0) {
                    dest[i - 1][j] = '.';
                }
                if (i + 1 < r) {
                    dest[i + 1][j] = '.';
                }
                if (j > 0) {
                    dest[i][j - 1] = '.';
                }
                if (j + 1 < c) {
                    dest[i][j + 1] = '.';
                }
            }
        }
    }
}

static void print_grid(char **grid, int r) {
    for (int i = 0; i < r; i++) {
        printf("%s\n", grid[i]);
    }
}

int main(void) {
    int r;
    int c;
    long long n;
    if (scanf("%d %d %lld", &r, &c, &n) != 3) {
        return 0;
    }

    char **initial = alloc_grid(r, c);
    if (!initial) {
        return 0;
    }

    for (int i = 0; i < r; i++) {
        if (scanf("%s", initial[i]) != 1) {
            free_grid(initial, r);
            return 0;
        }
    }

    if (n == 1) {
        print_grid(initial, r);
        free_grid(initial, r);
        return 0;
    }

    if (n % 2 == 0) {
        char **full = alloc_grid(r, c);
        if (!full) {
            free_grid(initial, r);
            return 0;
        }
        fill_full(full, r, c);
        print_grid(full, r);
        free_grid(full, r);
        free_grid(initial, r);
        return 0;
    }

    char **state1 = alloc_grid(r, c);
    char **state2 = alloc_grid(r, c);
    if (!state1 || !state2) {
        free_grid(initial, r);
        free_grid(state1, r);
        free_grid(state2, r);
        return 0;
    }

    explode(initial, state1, r, c);
    explode(state1, state2, r, c);

    char **result = (n % 4 == 3) ? state1 : state2;
    print_grid(result, r);

    free_grid(initial, r);
    free_grid(state1, r);
    free_grid(state2, r);
    return 0;
}

