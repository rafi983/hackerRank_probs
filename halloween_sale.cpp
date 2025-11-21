#include <iostream>
#include <algorithm>

using namespace std;

int howManyGames(int p, int d, int m, int s) {
    int count = 0;
    int price = p;
    while (s >= price) {
        s -= price;
        ++count;
        const int nextPrice = price - d;
        price = nextPrice > m ? nextPrice : m;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, d, m, s;
    if (!(cin >> p >> d >> m >> s)) {
        return 0;
    }

    cout << howManyGames(p, d, m, s) << '\n';
    return 0;
}

