#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int designerPdfViewer(const vector<int> &heights, const string &word) {
    int tallest = 0;
    for (char ch : word) {
        tallest = max(tallest, heights[ch - 'a']);
    }
    return tallest * static_cast<int>(word.size());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> heights(26);
    for (int &h : heights) {
        cin >> h;
    }

    string word;
    cin >> word;

    cout << designerPdfViewer(heights, word) << '\n';
    return 0;
}

