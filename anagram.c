#include <stdio.h>
#include <string.h>

int anagram(char* s) {
    int len = strlen(s);

    if (len % 2 == 1) {
        return -1;
    }

    int mid = len / 2;
    int freq1[26] = {0};
    int freq2[26] = {0};

    for (int i = 0; i < mid; i++) {
        freq1[s[i] - 'a']++;
        freq2[s[mid + i] - 'a']++;
    }

    int changes = 0;
    for (int i = 0; i < 26; i++) {
        if (freq1[i] > freq2[i]) {
            changes += freq1[i] - freq2[i];
        }
    }

    return changes;
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        char s[10001];
        scanf("%s", s);

        int result = anagram(s);
        printf("%d\n", result);
    }

    return 0;
}
