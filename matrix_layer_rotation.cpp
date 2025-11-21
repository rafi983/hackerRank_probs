#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void matrixRotation(int m, int n, int r, vector<vector<int>> &matrix) {
    const int numLayers = min(m, n) / 2;

    for (int layer = 0; layer < numLayers; ++layer) {
        const int rows = m - 2 * layer;
        const int cols = n - 2 * layer;
        const int perimeter = 2 * (rows + cols - 2);
        const int rotations = r % perimeter;
        if (rotations == 0) {
            continue;
        }

        vector<int> buffer;
        buffer.reserve(perimeter);

        // Top row
        for (int j = layer; j < n - layer - 1; ++j) buffer.push_back(matrix[layer][j]);
        // Right column
        for (int i = layer; i < m - layer - 1; ++i) buffer.push_back(matrix[i][n - 1 - layer]);
        // Bottom row
        for (int j = n - 1 - layer; j > layer; --j) buffer.push_back(matrix[m - 1 - layer][j]);
        // Left column
        for (int i = m - 1 - layer; i > layer; --i) buffer.push_back(matrix[i][layer]);

        int idx = 0;
        auto shifted = [&](int offset) {
            return buffer[(offset + rotations) % perimeter];
        };

        // Top row
        for (int j = layer; j < n - layer - 1; ++j) matrix[layer][j] = shifted(idx++);
        // Right column
        for (int i = layer; i < m - layer - 1; ++i) matrix[i][n - 1 - layer] = shifted(idx++);
        // Bottom row
        for (int j = n - 1 - layer; j > layer; --j) matrix[m - 1 - layer][j] = shifted(idx++);
        // Left column
        for (int i = m - 1 - layer; i > layer; --i) matrix[i][layer] = shifted(idx++);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, r;
    if (!(cin >> m >> n >> r)) {
        return 0;
    }

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    matrixRotation(m, n, r, matrix);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << (j + 1 == n ? '\n' : ' ');
        }
    }

    return 0;
}

