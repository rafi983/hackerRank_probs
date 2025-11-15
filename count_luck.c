#include <stdio.h>
#include <string.h>

#define MAX_R 100
#define MAX_C 100

static int rows;
static int cols;
static char grid[MAX_R][MAX_C + 1];
static int visited[MAX_R][MAX_C];

static const int DR[4] = {-1, 0, 0, 1};
static const int DC[4] = {0, -1, 1, 0};

static int dfs(int r, int c) {
    if (grid[r][c] == '*') {
        return 0;
    }

    visited[r][c] = 1;

    int next_rows[4];
    int next_cols[4];
    int options = 0;

    for (int dir = 0; dir < 4; dir++) {
        int nr = r + DR[dir];
        int nc = c + DC[dir];
        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
            continue;
        }
        if (grid[nr][nc] == 'X' || visited[nr][nc]) {
            continue;
        }
        next_rows[options] = nr;
        next_cols[options] = nc;
        options++;
    }

    for (int i = 0; i < options; i++) {
        int result = dfs(next_rows[i], next_cols[i]);
        if (result != -1) {
            if (options > 1) {
                return result + 1;
            }
            return result;
        }
    }

    return -1;
}

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }

    while (t--) {
        if (scanf("%d %d", &rows, &cols) != 2) {
            return 0;
        }

        for (int i = 0; i < rows; i++) {
            if (scanf("%s", grid[i]) != 1) {
                return 0;
            }
        }

        int guess;
        if (scanf("%d", &guess) != 1) {
            return 0;
        }

        int start_r = -1;
        int start_c = -1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 'M') {
                    start_r = i;
                    start_c = j;
                }
                visited[i][j] = 0;
            }
        }

        int decisions = dfs(start_r, start_c);
        if (decisions == guess) {
            printf("Impressed\n");
        } else {
            printf("Oops!\n");
        }
    }

    return 0;
}

