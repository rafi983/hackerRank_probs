#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 100000
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

static void swap_chars(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

static void reverse_suffix(char *s, int start, int end) {
    while (start < end) {
        swap_chars(&s[start], &s[end]);
        start++;
        end--;
    }
}

static int next_greater_word(char *s) {
    int len = (int)strlen(s);
    if (len <= 1) {
        return 0;
    }

    int pivot = len - 2;
    while (pivot >= 0 && s[pivot] >= s[pivot + 1]) {
        pivot--;
    }

    if (pivot < 0) {
        return 0;
    }

    int successor = len - 1;
    while (successor > pivot && s[successor] <= s[pivot]) {
        successor--;
    }

    swap_chars(&s[pivot], &s[successor]);
    reverse_suffix(s, pivot + 1, len - 1);
    return 1;
}

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }

    char word[MAX_WORD_LENGTH + 2];
    while (t--) {
        if (scanf("%" STR(MAX_WORD_LENGTH) "s", word) != 1) {
            return 0;
        }
        if (next_greater_word(word)) {
            printf("%s\n", word);
        } else {
            printf("no answer\n");
        }
    }

    return 0;
}
