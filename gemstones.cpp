#include <iostream>
#include <vector>
#include <string>

int gemstones(const std::vector<std::string> &rocks) {
    int gemstoneCount = 0;

    for (char mineral = 'a'; mineral <= 'z'; ++mineral) {
        bool isGemstone = true;
        for (const auto &rock : rocks) {
            if (rock.find(mineral) == std::string::npos) {
                isGemstone = false;
                break;
            }
        }
        if (isGemstone) {
            ++gemstoneCount;
        }
    }

    return gemstoneCount;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::vector<std::string> rocks(n);
    for (auto &rock : rocks) {
        std::cin >> rock;
    }

    std::cout << gemstones(rocks) << '\n';
    return 0;
}

