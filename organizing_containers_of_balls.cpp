#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) {
        return 0;
    }

    while (q--) {
        int n;
        if (!(cin >> n)) {
            return 0;
        }

        vector<long long> container(n, 0);
        vector<long long> type(n, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                long long val;
                if (!(cin >> val)) {
                    return 0;
                }
                container[i] += val;
                type[j] += val;
            }
        }

        sort(container.begin(), container.end());
        sort(type.begin(), type.end());

        bool possible = equal(container.begin(), container.end(), type.begin());
        cout << (possible ? "Possible" : "Impossible") << '\n';
    }

    return 0;
}

