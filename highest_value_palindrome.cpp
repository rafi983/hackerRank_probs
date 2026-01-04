#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string highestValuePalindrome(string s, int n, int k) {
    if (n == 0) return "";

    vector<bool> changed(n / 2, false);

    // First pass: Make it a palindrome with minimum changes
    for (int i = 0; i < n / 2; ++i) {
        int j = n - 1 - i;
        if (s[i] != s[j]) {
            char maxChar = max(s[i], s[j]);
            s[i] = maxChar;
            s[j] = maxChar;
            changed[i] = true;
            k--;
        }
    }

    if (k < 0) return "-1";

    // Second pass: Maximize the value
    for (int i = 0; i < n / 2; ++i) {
        int j = n - 1 - i;
        if (s[i] != '9') {
            if (changed[i]) {
                // Already spent 1 change, need 1 more to make both '9'
                if (k >= 1) {
                    s[i] = '9';
                    s[j] = '9';
                    k--;
                }
            } else {
                // Didn't change, need 2 changes to make both '9'
                if (k >= 2) {
                    s[i] = '9';
                    s[j] = '9';
                    k -= 2;
                }
            }
        }
    }

    // Handle the middle element if length is odd and we have changes left
    if (n % 2 == 1 && k > 0) {
        s[n / 2] = '9';
    }

    return s;
}

int main() {
    int n, k;
    string s;
    if (cin >> n >> k >> s) {
        cout << highestValuePalindrome(s, n, k) << endl;
    }
    return 0;
}
