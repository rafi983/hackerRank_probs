#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENDITURE 200

static int find_twice_median(const int *counts, int d) {
    int target1 = (d + 1) / 2;
    int target2 = (d % 2 == 0) ? (target1 + 1) : target1;
    int cumulative = 0;
    int first_value = 0;
    int second_value = 0;

    for (int value = 0; value <= MAX_EXPENDITURE; value++) {
        cumulative += counts[value];
        if (!first_value && cumulative >= target1) {
            first_value = value;
        }
        if (!second_value && cumulative >= target2) {
            second_value = value;
            break;
        }
    }

    return first_value + second_value;
}

int main(void) {
    int n;
    int d;
    if (scanf("%d %d", &n, &d) != 2 || n <= 0 || d <= 0 || d > n) {
        return 0;
    }

    int *expenditure = malloc(sizeof(int) * n);
    if (!expenditure) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &expenditure[i]) != 1) {
            return 0;
        }
    }

    int counts[MAX_EXPENDITURE + 1] = {0};
    for (int i = 0; i < d; i++) {
        counts[expenditure[i]]++;
    }

    int notifications = 0;
    for (int i = d; i < n; i++) {
        int twice_median = find_twice_median(counts, d);
        if (expenditure[i] >= twice_median) {
            notifications++;
        }
        counts[expenditure[i - d]]--;
        counts[expenditure[i]]++;
    }

    printf("%d\n", notifications);

    return 0;
}

