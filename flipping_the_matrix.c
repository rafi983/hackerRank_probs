#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int flippingMatrix(int n, int** matrix) {
    int sum = 0;
    int size = 2 * n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val1 = matrix[i][j];
            int val2 = matrix[i][size - 1 - j];
            int val3 = matrix[size - 1 - i][j];
            int val4 = matrix[size - 1 - i][size - 1 - j];

            sum += max(val1, max(val2, max(val3, val4)));
        }
    }
    return sum;
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n;
        scanf("%d", &n);
        int size = 2 * n;
        int** matrix = (int**)malloc(size * sizeof(int*));
        for (int i = 0; i < size; i++) {
            matrix[i] = (int*)malloc(size * sizeof(int));
            for (int j = 0; j < size; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        int result = flippingMatrix(n, matrix);
        printf("%d\n", result);

        for (int i = 0; i < size; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }
    return 0;
}