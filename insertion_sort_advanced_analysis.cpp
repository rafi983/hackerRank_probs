#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

long long _mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long inv_count = 0;
    if (right > left) {
        int mid = (right + left) / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}

long long countInversions(vector<int>& arr) {
    vector<int> temp(arr.size());
    return _mergeSort(arr, temp, 0, arr.size() - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            vector<int> arr(n);
            for (int i = 0; i < n; ++i) {
                cin >> arr[i];
            }
            cout << countInversions(arr) << endl;
        }
    }
    return 0;
}

