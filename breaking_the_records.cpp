#include <iostream>
#include <vector>

static std::pair<int, int> breakingRecords(const std::vector<int>& scores) {
    int maxRecord = scores.front();
    int minRecord = scores.front();
    int maxBreaks = 0;
    int minBreaks = 0;

    for (std::size_t i = 1; i < scores.size(); ++i) {
        if (scores[i] > maxRecord) {
            maxRecord = scores[i];
            ++maxBreaks;
        } else if (scores[i] < minRecord) {
            minRecord = scores[i];
            ++minBreaks;
        }
    }

    return {maxBreaks, minBreaks};
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::vector<int> scores(n);
    for (int& score : scores) {
        std::cin >> score;
    }

    const auto result = breakingRecords(scores);
    std::cout << result.first << ' ' << result.second << '\n';
    return 0;
}

