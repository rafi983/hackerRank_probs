#include <iostream>
#include <vector>

using namespace std;

int getMoneySpent(const vector<int> &keyboards, const vector<int> &drives, int budget) {
    int max_cost = -1;
    for (int keyboard_price : keyboards) {
        for (int drive_price : drives) {
            const int total_cost = keyboard_price + drive_price;
            if (total_cost <= budget && total_cost > max_cost) {
                max_cost = total_cost;
            }
        }
    }
    return max_cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int budget, keyboard_count, drive_count;
    if (!(cin >> budget >> keyboard_count >> drive_count)) {
        return 0;
    }

    vector<int> keyboards(keyboard_count);
    for (int &price : keyboards) {
        cin >> price;
    }

    vector<int> drives(drive_count);
    for (int &price : drives) {
        cin >> price;
    }

    cout << getMoneySpent(keyboards, drives, budget) << '\n';
    return 0;
}

