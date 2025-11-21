#include <iostream>
#include <vector>

using namespace std;

int fairRations(vector<int> &bread) {
    int distributed = 0;
    const int n = static_cast<int>(bread.size());

    for (int i = 0; i < n - 1; ++i) {
        if (bread[i] & 1) {
            ++bread[i];
            ++bread[i + 1];
            distributed += 2;
        }
    }

    if (n > 0 && (bread.back() & 1)) {
        return -1;
    }
    return distributed;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<int> bread(n);
    for (int &value : bread) {
        cin >> value;
    }

    const int result = fairRations(bread);
    if (result < 0) {
        cout << "NO\n";
    } else {
        cout << result << '\n';
    }
    return 0;
}

