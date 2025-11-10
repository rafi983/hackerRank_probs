#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int H, W;
    scanf("%d %d", &H, &W);

    int** A = (int**)malloc(H * sizeof(int*));
    for (int i = 0; i < H; i++) {
        A[i] = (int*)malloc(W * sizeof(int));
        for (int j = 0; j < W; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    long total_area = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] > 0) {
                total_area += 2 + (4L * A[i][j]);
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W - 1; j++) {
            total_area -= 2L * min(A[i][j], A[i][j + 1]);
        }
    }

    for (int i = 0; i < H - 1; i++) {
        for (int j = 0; j < W; j++) {
            total_area -= 2L * min(A[i][j], A[i + 1][j]);
        }
    }

    printf("%ld\n", total_area);

    for (int i = 0; i < H; i++) {
        free(A[i]);
    }
    free(A);

    return 0;
}

