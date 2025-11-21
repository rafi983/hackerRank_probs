#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

string dayOfProgrammer(int year) {
    if (year == 1918) {
        return "26.09.1918";
    }

    bool isLeap = false;
    if (year < 1918) {
        isLeap = (year % 4 == 0);
    } else {
        isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }

    const int daysTillAugust = isLeap ? 244 : 243;
    const int dayInSeptember = 256 - daysTillAugust;

    ostringstream oss;
    oss << setfill('0') << setw(2) << dayInSeptember << ".09." << year;
    return oss.str();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int year;
    if (!(cin >> year)) {
        return 0;
    }

    cout << dayOfProgrammer(year) << '\n';
    return 0;
}

