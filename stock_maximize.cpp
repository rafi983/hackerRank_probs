#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long stockmax(vector<int> prices) {
    long long profit = 0;
    int max_so_far = 0;

    for (int i = prices.size() - 1; i >= 0; --i) {
        if (prices[i] >= max_so_far) {
            max_so_far = prices[i];
        } else {
            profit += (long long)(max_so_far - prices[i]);
        }
    }

    return profit;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            vector<int> prices(n);
            for (int i = 0; i < n; ++i) {
                cin >> prices[i];
            }
            cout << stockmax(prices) << endl;
        }
    }
    return 0;
}
