#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> z_function(const string& s) {
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

long long stringSimilarity(string s) {
    if (s.empty()) return 0;

    vector<int> z = z_function(s);

    long long total_similarity = s.length();

    for (int i = 1; i < s.length(); i++) {
        total_similarity += z[i];
    }

    return total_similarity;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << stringSimilarity(s) << endl;
    }
    return 0;
}
