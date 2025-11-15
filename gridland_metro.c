#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long row;
    long long start;
    long long end;
} Track;

static int compare_tracks(const void *a, const void *b) {
    const Track *ta = (const Track *)a;
    const Track *tb = (const Track *)b;
    if (ta->row < tb->row) {
        return -1;
    }
    if (ta->row > tb->row) {
        return 1;
    }
    if (ta->start < tb->start) {
        return -1;
    }
    if (ta->start > tb->start) {
        return 1;
    }
    if (ta->end < tb->end) {
        return -1;
    }
    if (ta->end > tb->end) {
        return 1;
    }
    return 0;
}

int main(void) {
    long long n;
    long long m;
    long long k;
    if (scanf("%lld %lld %lld", &n, &m, &k) != 3) {
        return 0;
    }

    if (k <= 0) {
        long long total = n * m;
        printf("%lld\n", total);
        return 0;
    }

    Track *tracks = malloc(sizeof(Track) * (size_t)k);
    if (!tracks) {
        return 0;
    }

    for (long long i = 0; i < k; i++) {
        long long r;
        long long c1;
        long long c2;
        if (scanf("%lld %lld %lld", &r, &c1, &c2) != 3) {
            return 0;
        }
        if (c1 > c2) {
            long long tmp = c1;
            c1 = c2;
            c2 = tmp;
        }
        tracks[i].row = r;
        tracks[i].start = c1;
        tracks[i].end = c2;
    }

    qsort(tracks, (size_t)k, sizeof(Track), compare_tracks);

    long long covered = 0;
    long long current_row = tracks[0].row;
    long long current_start = tracks[0].start;
    long long current_end = tracks[0].end;

    for (long long i = 1; i < k; i++) {
        if (tracks[i].row != current_row) {
            covered += current_end - current_start + 1;
            current_row = tracks[i].row;
            current_start = tracks[i].start;
            current_end = tracks[i].end;
            continue;
        }

        if (tracks[i].start > current_end) {
            covered += current_end - current_start + 1;
            current_start = tracks[i].start;
            current_end = tracks[i].end;
        } else if (tracks[i].end > current_end) {
            current_end = tracks[i].end;
        }
    }

    covered += current_end - current_start + 1;

    long long total_cells = n * m;
    long long lampposts = total_cells - covered;
    printf("%lld\n", lampposts);

    return 0;
}

