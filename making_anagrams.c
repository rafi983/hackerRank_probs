#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int makingAnagrams(char* s1, char* s2) {
    int freq1[26] = {0};
    int freq2[26] = {0};

    for (int i = 0; s1[i] != '\0'; i++) {
        freq1[s1[i] - 'a']++;
    }

    for (int i = 0; s2[i] != '\0'; i++) {
        freq2[s2[i] - 'a']++;
    }

    int deletions = 0;
    for (int i = 0; i < 26; i++) {
        deletions += abs(freq1[i] - freq2[i]);
    }

    return deletions;
}

int main() {
    char s1[10001];
    char s2[10001];

    scanf("%s", s1);
    scanf("%s", s2);

    int result = makingAnagrams(s1, s2);
    printf("%d\n", result);

    return 0;
}
