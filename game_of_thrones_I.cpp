#include <iostream>
#include <string>
#include <array>

using namespace std;

string gameOfThrones(const string &s) {
    array<int, 26> freq{};
    for (char ch : s) {
        ++freq[ch - 'a'];
    }

    int oddCount = 0;
    for (int f : freq) {
        if (f & 1) {
            ++oddCount;
            if (oddCount > 1) {
                return "NO";
            }
        }
    }
    return "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) {
        return 0;
    }

    cout << gameOfThrones(s) << '\n';
    return 0;
}

