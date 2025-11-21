#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1;
    string s2;
    if (!(cin >> s1 >> s2)) {
        return 0;
    }

    const int len1 = static_cast<int>(s1.size());
    const int len2 = static_cast<int>(s2.size());

    vector<int> prev(len2 + 1, 0);
    vector<int> curr(len2 + 1, 0);

    for (int i = 1; i <= len1; ++i) {
        curr[0] = 0;
        for (int j = 1; j <= len2; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                curr[j] = prev[j - 1] + 1;
            } else {
                curr[j] = max(curr[j - 1], prev[j]);
            }
        }
        swap(prev, curr);
    }

    cout << prev[len2] << '\n';
    return 0;
}

