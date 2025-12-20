#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pylons(int k, vector<int> arr) {
    int n = arr.size();
    int plants = 0;
    int i = 0;

    while (i < n) {
        int loc = min(n - 1, i + k - 1);
        bool found = false;

        // Search backwards for a suitable location
        while (loc >= i - k + 1 && loc >= 0) {
            if (arr[loc] == 1) {
                found = true;
                break;
            }
            loc--;
        }

        if (!found) {
            return -1;
        }

        plants++;
        i = loc + k;
    }

    return plants;
}

int main() {
    int n, k;
    if (cin >> n >> k) {
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cout << pylons(k, arr) << endl;
    }
    return 0;
}
