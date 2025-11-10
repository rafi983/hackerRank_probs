#include <stdio.h>
#include <stdlib.h>

void matrixRotation(int m, int n, int r, int** matrix) {
    int num_layers = (m < n ? m : n) / 2;

    for (int l = 0; l < num_layers; l++) {
        int rows = m - 2 * l;
        int cols = n - 2 * l;
        int perimeter = 2 * (rows + cols - 2);
        int actual_rotations = r % perimeter;

        if (actual_rotations == 0) {
            continue;
        }

        int* layer_array = (int*)malloc(perimeter * sizeof(int));
        int current = 0;

        // Top row
        for (int j = l; j < n - l - 1; j++) layer_array[current++] = matrix[l][j];
        // Right col
        for (int i = l; i < m - l - 1; i++) layer_array[current++] = matrix[i][n - 1 - l];
        // Bottom row
        for (int j = n - 1 - l; j > l; j--) layer_array[current++] = matrix[m - 1 - l][j];
        // Left col
        for (int i = m - 1 - l; i > l; i--) layer_array[current++] = matrix[i][l];

        current = 0;
        // Top row
        for (int j = l; j < n - l - 1; j++) matrix[l][j] = layer_array[(current++ + actual_rotations) % perimeter];
        // Right col
        for (int i = l; i < m - l - 1; i++) matrix[i][n - 1 - l] = layer_array[(current++ + actual_rotations) % perimeter];
        // Bottom row
        for (int j = n - 1 - l; j > l; j--) matrix[m - 1 - l][j] = layer_array[(current++ + actual_rotations) % perimeter];
        // Left col
        for (int i = m - 1 - l; i > l; i--) matrix[i][l] = layer_array[(current++ + actual_rotations) % perimeter];

        free(layer_array);
    }
}

int main() {
    int m, n, r;
    scanf("%d %d %d", &m, &n, &r);

    int** matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    matrixRotation(m, n, r, matrix);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
