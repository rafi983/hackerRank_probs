#include <stdio.h>
#include <string.h>

static const char* num_words[] = {
    "zero","one","two","three","four","five","six","seven","eight","nine","ten",
    "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty",
    "twenty one","twenty two","twenty three","twenty four","twenty five","twenty six","twenty seven","twenty eight","twenty nine"
};

static const char* word(int n){ return num_words[n]; }

static const char* timeInWords(int h, int m) {
    static char buf[64];
    buf[0] = '\0';
    if (m == 0) {
        snprintf(buf, sizeof(buf), "%s o' clock", word(h));
    } else if (m == 15) {
        snprintf(buf, sizeof(buf), "quarter past %s", word(h));
    } else if (m == 30) {
        snprintf(buf, sizeof(buf), "half past %s", word(h));
    } else if (m == 45) {
        int nh = h == 12 ? 1 : h + 1;
        snprintf(buf, sizeof(buf), "quarter to %s", word(nh));
    } else if (m < 30) {
        if (m == 1) snprintf(buf, sizeof(buf), "one minute past %s", word(h));
        else snprintf(buf, sizeof(buf), "%s minutes past %s", word(m), word(h));
    } else {
        int rem = 60 - m;
        int nh = h == 12 ? 1 : h + 1;
        if (rem == 1) snprintf(buf, sizeof(buf), "one minute to %s", word(nh));
        else snprintf(buf, sizeof(buf), "%s minutes to %s", word(rem), word(nh));
    }
    return buf;
}

int main(void) {
    int h, m;
    if (scanf("%d", &h) != 1) return 0;
    if (scanf("%d", &m) != 1) return 0;
    const char* res = timeInWords(h, m);
    printf("%s\n", res);
    return 0;
}

