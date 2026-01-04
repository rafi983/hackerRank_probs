#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int d_up = n - r_q;
    int d_down = r_q - 1;
    int d_right = n - c_q;
    int d_left = c_q - 1;
    int d_up_right = min(n - r_q, n - c_q);
    int d_up_left = min(n - r_q, c_q - 1);
    int d_down_right = min(r_q - 1, n - c_q);
    int d_down_left = min(r_q - 1, c_q - 1);

    for (const auto& obs : obstacles) {
        int r_o = obs[0];
        int c_o = obs[1];

        if (c_o == c_q) {
            if (r_o > r_q) {
                d_up = min(d_up, r_o - r_q - 1);
            } else {
                d_down = min(d_down, r_q - r_o - 1);
            }
        } else if (r_o == r_q) {
            if (c_o > c_q) {
                d_right = min(d_right, c_o - c_q - 1);
            } else {
                d_left = min(d_left, c_q - c_o - 1);
            }
        } else if (abs(r_o - r_q) == abs(c_o - c_q)) {
            if (r_o > r_q) {
                if (c_o > c_q) {
                    d_up_right = min(d_up_right, r_o - r_q - 1);
                } else {
                    d_up_left = min(d_up_left, r_o - r_q - 1);
                }
            } else {
                if (c_o > c_q) {
                    d_down_right = min(d_down_right, r_q - r_o - 1);
                } else {
                    d_down_left = min(d_down_left, r_q - r_o - 1);
                }
            }
        }
    }

    return d_up + d_down + d_right + d_left + d_up_right + d_up_left + d_down_right + d_down_left;
}

int main() {
    int n, k;
    if (cin >> n >> k) {
        int r_q, c_q;
        cin >> r_q >> c_q;
        vector<vector<int>> obstacles(k, vector<int>(2));
        for (int i = 0; i < k; ++i) {
            cin >> obstacles[i][0] >> obstacles[i][1];
        }
        cout << queensAttack(n, k, r_q, c_q, obstacles) << endl;
    }
    return 0;
}
