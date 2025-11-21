#include <iostream>
#include <vector>

using namespace std;

vector<int> countingSort(const vector<int> &arr) {
    vector<int> freq(100, 0);
    for (int value : arr) {
        freq[value]++;
    }
    return freq;
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

    vector<int> result = countingSort(arr);
    for (int i = 0; i < 100; ++i) {
        if (i) {
            cout << ' ';
        }
        cout << result[i];
    }
    cout << '\n';
    return 0;
}

