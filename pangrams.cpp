#include <iostream>
#include <string>
#include <array>
#include <cctype>

using namespace std;

string pangrams(const string &s) {
    array<bool, 26> letters{};
    int uniqueCount = 0;

    for (char ch : s) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            char lowered = tolower(static_cast<unsigned char>(ch));
            int index = lowered - 'a';
            if (!letters[index]) {
                letters[index] = true;
                if (++uniqueCount == 26) {
                    return "pangram";
                }
            }
        }
    }

    return "not pangram";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    cout << pangrams(s) << '\n';
    return 0;
}

