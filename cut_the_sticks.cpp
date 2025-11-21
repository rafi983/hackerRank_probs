#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cutTheSticks(vector<int> arr) {
    vector<int> result;
    result.reserve(arr.size());

    sort(arr.begin(), arr.end());
    size_t i = 0;
    const size_t n = arr.size();

    while (i < n) {
        result.push_back(static_cast<int>(n - i));

        const int currentLength = arr[i];
        while (i < n && arr[i] == currentLength) {
            ++i;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<int> arr(n);
    for (int &value : arr) {
        cin >> value;
    }

    const vector<int> result = cutTheSticks(arr);
    for (int value : result) {
        cout << value << '\n';
    }

    return 0;
}

