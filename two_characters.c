#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


static int max_alternating_two_chars(const char *s) {
    int present[26] = {0};
    int n = (int)strlen(s);
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') present[c - 'a'] = 1;
    }

    int best = 0;
    for (int a = 0; a < 26; ++a) {
        if (!present[a]) continue;
        for (int b = a + 1; b < 26; ++b) {
            if (!present[b]) continue;

            char ca = (char)('a' + a);
            char cb = (char)('a' + b);
            char prev = 0;
            int len = 0;
            int cntA = 0, cntB = 0;
            bool ok = true;

            for (int i = 0; i < n; ++i) {
                char c = s[i];
                if (c != ca && c != cb) continue;
                if (prev == c) { ok = false; break; }
                prev = c;
                len++;
                if (c == ca) cntA++; else cntB++;
            }

            if (ok && cntA > 0 && cntB > 0 && len > best) best = len;
        }
    }

    return best;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char *s = (char *)malloc((size_t)n + 5u);
    if (!s) return 1;
    if (scanf("%s", s) != 1) { free(s); return 0; }

    int ans = max_alternating_two_chars(s);
    printf("%d\n", ans);

    free(s);
    return 0;
}

