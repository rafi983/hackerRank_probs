#include <iostream>
#include <vector>

using namespace std;

vector<int> circularArrayRotation(const vector<int> &a, int k, const vector<int> &queries) {
    const int n = static_cast<int>(a.size());
    vector<int> result;
    result.reserve(queries.size());
    k %= n;

    for (int queryIndex : queries) {
        int originalIndex = (queryIndex - k) % n;
        if (originalIndex < 0) {
            originalIndex += n;
        }
        result.push_back(a[originalIndex]);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    if (!(cin >> n >> k >> q)) {
        return 0;
    }

    vector<int> a(n);
    for (int &value : a) {
        cin >> value;
    }

    vector<int> queries(q);
    for (int &query : queries) {
        cin >> query;
    }

    vector<int> result = circularArrayRotation(a, k, queries);
    for (int value : result) {
        cout << value << '\n';
    }

    return 0;
}

