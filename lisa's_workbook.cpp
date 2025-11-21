#include <iostream>
#include <vector>

using namespace std;

int workbook(int n, int k, const vector<int> &arr) {
    int specialProblems = 0;
    int pageNumber = 1;

    for (int chapter = 0; chapter < n; ++chapter) {
        const int problems = arr[chapter];
        for (int problem = 1; problem <= problems; ++problem) {
            if (problem == pageNumber) {
                ++specialProblems;
            }
            if (problem % k == 0 || problem == problems) {
                ++pageNumber;
            }
        }
    }

    return specialProblems;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) {
        return 0;
    }

    vector<int> arr(n);
    for (int &problems : arr) {
        cin >> problems;
    }

    cout << workbook(n, k, arr) << '\n';
    return 0;
}

