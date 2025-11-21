#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Track {
    long long row;
    long long start;
    long long end;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    long long m;
    long long k;
    if (!(cin >> n >> m >> k)) {
        return 0;
    }

    if (k <= 0) {
        cout << n * m << '\n';
        return 0;
    }

    vector<Track> tracks(k);
    for (long long i = 0; i < k; ++i) {
        long long r;
        long long c1;
        long long c2;
        cin >> r >> c1 >> c2;
        if (c1 > c2) {
            swap(c1, c2);
        }
        tracks[i] = Track{r, c1, c2};
    }

    sort(tracks.begin(), tracks.end(), [](const Track &a, const Track &b) {
        if (a.row != b.row) {
            return a.row < b.row;
        }
        if (a.start != b.start) {
            return a.start < b.start;
        }
        return a.end < b.end;
    });

    long long covered = 0;
    long long currentRow = tracks[0].row;
    long long currentStart = tracks[0].start;
    long long currentEnd = tracks[0].end;

    for (long long i = 1; i < k; ++i) {
        if (tracks[i].row != currentRow) {
            covered += currentEnd - currentStart + 1;
            currentRow = tracks[i].row;
            currentStart = tracks[i].start;
            currentEnd = tracks[i].end;
            continue;
        }

        if (tracks[i].start > currentEnd) {
            covered += currentEnd - currentStart + 1;
            currentStart = tracks[i].start;
            currentEnd = tracks[i].end;
        } else if (tracks[i].end > currentEnd) {
            currentEnd = tracks[i].end;
        }
    }

    covered += currentEnd - currentStart + 1;

    const long long totalCells = n * m;
    const long long lampposts = totalCells - covered;
    cout << lampposts << '\n';

    return 0;
}

