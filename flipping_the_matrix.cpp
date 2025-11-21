#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int flippingMatrix(int n, const vector<vector<int>> &matrix) {
    int sum = 0;
    const int size = 2 * n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            const int val1 = matrix[i][j];
            const int val2 = matrix[i][size - 1 - j];
            const int val3 = matrix[size - 1 - i][j];
            const int val4 = matrix[size - 1 - i][size - 1 - j];
            sum += max({val1, val2, val3, val4});
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) {
        return 0;
    }

    while (q--) {
        int n;
        cin >> n;
        const int size = 2 * n;
        vector<vector<int>> matrix(size, vector<int>(size));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cin >> matrix[i][j];
            }
        }
        cout << flippingMatrix(n, matrix) << '\n';
    }

    return 0;
}

