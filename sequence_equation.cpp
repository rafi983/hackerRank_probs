#include <iostream>
#include <vector>

using namespace std;

vector<int> permutationEquation(const vector<int> &p) {
    const int n = static_cast<int>(p.size());
    vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        pos[p[i]] = i + 1;
    }

    vector<int> result(n + 1);
    for (int x = 1; x <= n; ++x) {
        const int indexOfX = pos[x];
        result[x] = pos[indexOfX];
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<int> p(n);
    for (int &value : p) {
        cin >> value;
    }

    vector<int> answers = permutationEquation(p);
    for (int x = 1; x <= n; ++x) {
        cout << answers[x] << '\n';
    }

    return 0;
}

