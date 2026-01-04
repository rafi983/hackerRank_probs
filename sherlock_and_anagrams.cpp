#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int sherlockAndAnagrams(string s) {
    map<string, int> counts;
    int n = s.length();

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            string sub = s.substr(i, len);
            sort(sub.begin(), sub.end());
            counts[sub]++;
        }
    }

    int totalPairs = 0;
    for (auto const& entry : counts) {
        int val = entry.second;
        totalPairs += val * (val - 1) / 2;
    }

    return totalPairs;
}

int main() {
    int q;
    if (cin >> q) {
        while (q--) {
            string s;
            cin >> s;
            cout << sherlockAndAnagrams(s) << endl;
        }
    }
    return 0;
}
