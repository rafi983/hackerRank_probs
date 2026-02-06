#include <iostream>
#include <vector>

using namespace std;

long long aVeryBigSum(vector<long long> ar) {
    long long sum = 0;
    for (size_t i = 0; i < ar.size(); i++) {
        sum += ar[i];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<long long> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    long long result = aVeryBigSum(ar);

    cout << result << endl;

    return 0;
}
