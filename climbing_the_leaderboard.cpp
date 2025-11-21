#include <iostream>
#include <vector>

using namespace std;

vector<int> climbingLeaderboard(const vector<int> &ranked, const vector<int> &player) {
    vector<int> unique;
    unique.reserve(ranked.size());

    for (int score : ranked) {
        if (unique.empty() || score != unique.back()) {
            unique.push_back(score);
        }
    }

    vector<int> result;
    result.reserve(player.size());

    int idx = static_cast<int>(unique.size()) - 1;
    for (int score : player) {
        while (idx >= 0 && score >= unique[idx]) {
            --idx;
        }
        result.push_back(idx + 2);
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

    vector<int> ranked(n);
    for (int &score : ranked) {
        cin >> score;
    }

    int m;
    cin >> m;
    vector<int> player(m);
    for (int &score : player) {
        cin >> score;
    }

    vector<int> result = climbingLeaderboard(ranked, player);
    for (int rank : result) {
        cout << rank << '\n';
    }

    return 0;
}

