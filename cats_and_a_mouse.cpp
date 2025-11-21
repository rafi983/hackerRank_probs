#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string catAndMouse(int x, int y, int z) {
    int distance_cat_a = abs(x - z);
    int distance_cat_b = abs(y - z);

    if (distance_cat_a < distance_cat_b) {
        return "Cat A";
    }
    if (distance_cat_b < distance_cat_a) {
        return "Cat B";
    }
    return "Mouse C";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) {
        return 0;
    }

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        cout << catAndMouse(x, y, z) << '\n';
    }

    return 0;
}

