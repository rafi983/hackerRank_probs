#include <iostream>
#include <vector>

using namespace std;

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    int alicePoints = 0;
    int bobPoints = 0;

    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) {
            alicePoints++;
        } else if (a[i] < b[i]) {
            bobPoints++;
        }
    }
    return {alicePoints, bobPoints};
}

int main() {
    vector<int> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }

    vector<int> b(3);
    for (int i = 0; i < 3; i++) {
        cin >> b[i];
    }

    vector<int> result = compareTriplets(a, b);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}
