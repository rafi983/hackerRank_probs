#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* gridSearch(int R, int C, char** G, int r, int c, char** P) {
    for (int i = 0; i <= R - r; i++) {
        for (int j = 0; j <= C - c; j++) {
            int found = 1;
            for (int k = 0; k < r; k++) {
                if (strncmp(&G[i + k][j], P[k], c) != 0) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                return "YES";
            }
        }
    }
    return "NO";
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int R, C;
        scanf("%d %d", &R, &C);
        char** G = malloc(R * sizeof(char*));
        for (int i = 0; i < R; i++) {
            G[i] = malloc((C + 1) * sizeof(char));
            scanf("%s", G[i]);
        }

        int r, c;
        scanf("%d %d", &r, &c);
        char** P = malloc(r * sizeof(char*));
        for (int i = 0; i < r; i++) {
            P[i] = malloc((c + 1) * sizeof(char));
            scanf("%s", P[i]);
        }

        char* result = gridSearch(R, C, G, r, c, P);
        printf("%s\n", result);

        for (int i = 0; i < R; i++) {
            free(G[i]);
        }
        free(G);

        for (int i = 0; i < r; i++) {
            free(P[i]);
        }
        free(P);
    }
    return 0;
}

