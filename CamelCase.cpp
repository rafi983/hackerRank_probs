#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int camelcase(const string &s) {
    int wordCount = 1;
    for (char ch : s) {
        if (isupper(static_cast<unsigned char>(ch))) {
            wordCount++;
        }
    }
    return wordCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) {
        return 0;
    }

    cout << camelcase(s) << '\n';
    return 0;
}

