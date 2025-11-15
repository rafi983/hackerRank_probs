#include <stdio.h>

static const int DR[6] = {-2, -2, 0, 2, 2, 0};
static const int DC[6] = {-1, 1, 2, 1, -1, -2};
static const char *MOVE_NAMES[6] = {"UL", "UR", "R", "LR", "LL", "L"};

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int r_start;
    int c_start;
    int r_end;
    int c_end;
    if (scanf("%d %d %d %d", &r_start, &c_start, &r_end, &c_end) != 4) {
        return 0;
    }

    if (r_start == r_end && c_start == c_end) {
        printf("0\n\n");
        return 0;
    }

    int total = n * n;
    int queue_r[total];
    int queue_c[total];
    int front = 0;
    int back = 0;

    char visited[n][n];
    int parent_r[n][n];
    int parent_c[n][n];
    int parent_move[n][n];
    int dist[n][n];

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            visited[r][c] = 0;
            parent_move[r][c] = -1;
            dist[r][c] = 0;
        }
    }

    visited[r_start][c_start] = 1;
    parent_r[r_start][c_start] = -1;
    parent_c[r_start][c_start] = -1;
    queue_r[back] = r_start;
    queue_c[back] = c_start;
    back++;

    int found = 0;
    while (front < back) {
        int r = queue_r[front];
        int c = queue_c[front];
        front++;

        if (r == r_end && c == c_end) {
            found = 1;
            break;
        }

        for (int move = 0; move < 6; move++) {
            int nr = r + DR[move];
            int nc = c + DC[move];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                continue;
            }
            if (visited[nr][nc]) {
                continue;
            }
            visited[nr][nc] = 1;
            parent_r[nr][nc] = r;
            parent_c[nr][nc] = c;
            parent_move[nr][nc] = move;
            dist[nr][nc] = dist[r][c] + 1;
            queue_r[back] = nr;
            queue_c[back] = nc;
            back++;
        }
    }

    if (!found) {
        printf("Impossible\n");
        return 0;
    }

    int path_len = dist[r_end][c_end];
    const char *path[path_len];
    int idx = path_len - 1;
    int r = r_end;
    int c = c_end;

    while (parent_move[r][c] != -1) {
        int move = parent_move[r][c];
        path[idx] = MOVE_NAMES[move];
        idx--;
        int pr = parent_r[r][c];
        int pc = parent_c[r][c];
        r = pr;
        c = pc;
    }

    printf("%d\n", path_len);
    for (int i = 0; i < path_len; i++) {
        printf("%s", path[i]);
        if (i + 1 < path_len) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}

