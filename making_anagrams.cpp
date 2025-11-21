#include <iostream>
#include <array>
#include <string>

using namespace std;

int makingAnagrams(const string &s1, const string &s2) {
    array<int, 26> freq1{};
    array<int, 26> freq2{};

    for (char ch : s1) {
        ++freq1[ch - 'a'];
    }
    for (char ch : s2) {
        ++freq2[ch - 'a'];
    }

    int deletions = 0;
    for (int i = 0; i < 26; ++i) {
        deletions += abs(freq1[i] - freq2[i]);
    }
    return deletions;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1;
    string s2;
    if (!(cin >> s1 >> s2)) {
        return 0;
    }

    cout << makingAnagrams(s1, s2) << '\n';
    return 0;
}

