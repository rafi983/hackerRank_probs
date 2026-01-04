#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int chiefHopper(vector<int> arr) {
    long long energy = 0;
    for (int i = arr.size() - 1; i >= 0; --i) {
        energy = (energy + arr[i] + 1) / 2;
    }
    return (int)energy;
}

int main() {
    int n;
    if (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << chiefHopper(arr) << endl;
    }
    return 0;
}
