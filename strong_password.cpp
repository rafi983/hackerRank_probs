#include <iostream>
#include <string>

int minimumNumber(int n, const std::string &password) {
    bool hasDigit = false;
    bool hasLower = false;
    bool hasUpper = false;
    bool hasSpecial = false;

    const std::string special = "!@#$%^&*()-+";

    for (char ch : password) {
        if (std::isdigit(static_cast<unsigned char>(ch))) {
            hasDigit = true;
        } else if (std::islower(static_cast<unsigned char>(ch))) {
            hasLower = true;
        } else if (std::isupper(static_cast<unsigned char>(ch))) {
            hasUpper = true;
        } else if (special.find(ch) != std::string::npos) {
            hasSpecial = true;
        }
    }

    int missingTypes = 0;
    if (!hasDigit) ++missingTypes;
    if (!hasLower) ++missingTypes;
    if (!hasUpper) ++missingTypes;
    if (!hasSpecial) ++missingTypes;

    int lengthNeeded = n < 6 ? 6 - n : 0;
    return std::max(missingTypes, lengthNeeded);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::string password;
    std::cin >> password;

    std::cout << minimumNumber(n, password) << '\n';
    return 0;
}

