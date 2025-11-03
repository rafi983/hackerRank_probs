#include <stdio.h>
#include <stdlib.h>

int findMin(int* arr, int n) {
    int min = 1001;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0 && arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int countSticks(int* arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            count++;
        }
    }
    return count;
}

int* cutTheSticks(int arr_count, int* arr, int* result_count) {
    int* result = (int*)malloc(arr_count * sizeof(int));
    *result_count = 0;

    while (1) {
        int remaining = countSticks(arr, arr_count);
        if (remaining == 0) break;

        result[*result_count] = remaining;
        (*result_count)++;

        int min_length = findMin(arr, arr_count);

        for (int i = 0; i < arr_count; i++) {
            if (arr[i] > 0) {
                arr[i] -= min_length;
            }
        }
    }

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result_count;
    int* result = cutTheSticks(n, arr, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }

    free(arr);
    free(result);

    return 0;
}
