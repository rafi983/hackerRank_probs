#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int k;
    if (!(cin >> n >> k) || n <= 0 || k < 0) {
        return 0;
    }

    vector<int> x(n);
    for (int &pos : x) {
        if (!(cin >> pos)) {
            return 0;
        }
    }

    sort(x.begin(), x.end());

    int transmitters = 0;
    int i = 0;
    while (i < n) {
        ++transmitters;

        int loc = x[i] + k;
        while (i < n && x[i] <= loc) {
            ++i;
        }

        int tower_pos = x[i - 1];
        loc = tower_pos + k;
        while (i < n && x[i] <= loc) {
            ++i;
        }
    }

    cout << transmitters << '\n';
    return 0;
}

