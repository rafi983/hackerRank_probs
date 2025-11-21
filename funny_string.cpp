#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string funnyString(const string &s) {
    const int len = static_cast<int>(s.size());
    for (int i = 0; i < len - 1; ++i) {
        const int diff1 = abs(s[i] - s[i + 1]);
        const int diff2 = abs(s[len - 1 - i] - s[len - 2 - i]);
        if (diff1 != diff2) {
            return "Not Funny";
        }
    }
    return "Funny";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) {
        return 0;
    }

    while (q--) {
        string s;
        cin >> s;
        cout << funnyString(s) << '\n';
    }

    return 0;
}

