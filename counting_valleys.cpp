#include <iostream>
#include <string>

using namespace std;

int countingValleys(int steps, const string &path) {
    int level = 0;
    int valleys = 0;
    bool inValley = false;

    for (int i = 0; i < steps; ++i) {
        if (path[i] == 'U') {
            ++level;
        } else if (path[i] == 'D') {
            --level;
        }

        if (level < 0 && !inValley) {
            inValley = true;
            ++valleys;
        } else if (level >= 0) {
            inValley = false;
        }
    }

    return valleys;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int steps;
    if (!(cin >> steps)) {
        return 0;
    }

    string path;
    cin >> path;

    cout << countingValleys(steps, path) << '\n';
    return 0;
}

