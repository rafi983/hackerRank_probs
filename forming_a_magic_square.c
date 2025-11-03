#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int magic_squares[8][3][3] = {
    {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
    {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
    {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
    {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
    {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
    {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
    {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
    {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
};

int formingMagicSquare(int s[3][3]) {
    int min_cost = 100000;

    for (int i = 0; i < 8; i++) {
        int current_cost = 0;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                current_cost += abs(s[j][k] - magic_squares[i][j][k]);
            }
        }
        if (current_cost < min_cost) {
            min_cost = current_cost;
        }
    }

    return min_cost;
}

int main() {
    int s[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &s[i][j]);
        }
    }

    int result = formingMagicSquare(s);
    printf("%d\n", result);

    return 0;
}
