#include <stdio.h>
#include <stdlib.h>

int is_valid(int r, int c, int n, int m) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

int dfs(int r, int c, int n, int m, int** matrix, int** visited) {
    if (!is_valid(r, c, n, m) || visited[r][c] || matrix[r][c] == 0) {
        return 0;
    }

    visited[r][c] = 1;
    int count = 1;

    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) {
                continue;
            }
            count += dfs(r + dr, c + dc, n, m, matrix, visited);
        }
    }

    return count;
}

int connectedCell(int n, int m, int** matrix) {
    int** visited = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        visited[i] = (int*)calloc(m, sizeof(int));
    }

    int max_region = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                int current_region_size = dfs(i, j, n, m, matrix, visited);
                if (current_region_size > max_region) {
                    max_region = current_region_size;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        free(visited[i]);
    }
    free(visited);

    return max_region;
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int result = connectedCell(n, m, matrix);
    printf("%d\n", result);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

