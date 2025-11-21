#include <iostream>
#include <vector>
#include <array>
#include <queue>

namespace {
constexpr int MAX_DISKS = 10;
constexpr int NUM_RODS = 4;
constexpr int MAX_STATES = 1 << 20;  // 4^10

using State = std::array<int, MAX_DISKS>;

int encodeState(const State &state, int disks) {
    int encoded = 0;
    for (int i = 0; i < disks; ++i) {
        encoded = encoded * NUM_RODS + (state[i] - 1);
    }
    return encoded;
}

bool isGoal(const State &state, int disks) {
    for (int i = 0; i < disks; ++i) {
        if (state[i] != 1) {
            return false;
        }
    }
    return true;
}

int getTopDisk(const State &state, int rod, int disks) {
    for (int i = 0; i < disks; ++i) {
        if (state[i] == rod) {
            return i;
        }
    }
    return -1;
}

bool canMove(const State &state, int from, int to, int disks) {
    const int diskFrom = getTopDisk(state, from, disks);
    if (diskFrom == -1) {
        return false;
    }

    const int diskTo = getTopDisk(state, to, disks);
    if (diskTo == -1) {
        return true;
    }

    return diskFrom < diskTo;
}

int bfs(const State &initial, int disks) {
    std::vector<char> visited(MAX_STATES, 0);
    std::queue<std::pair<State, int>> q;

    q.push({initial, 0});
    visited[encodeState(initial, disks)] = 1;

    while (!q.empty()) {
        const auto [currentState, moves] = q.front();
        q.pop();

        if (isGoal(currentState, disks)) {
            return moves;
        }

        for (int from = 1; from <= NUM_RODS; ++from) {
            for (int to = 1; to <= NUM_RODS; ++to) {
                if (from == to || !canMove(currentState, from, to, disks)) {
                    continue;
                }

                State nextState = currentState;
                const int disk = getTopDisk(nextState, from, disks);
                nextState[disk] = to;

                const int encoded = encodeState(nextState, disks);
                if (visited[encoded]) {
                    continue;
                }

                visited[encoded] = 1;
                q.push({nextState, moves + 1});
            }
        }
    }

    return -1;
}

int hanoi(int postsCount, const std::vector<int> &posts) {
    State initial{};
    initial.fill(1);
    for (int i = 0; i < postsCount; ++i) {
        initial[i] = posts[i];
    }
    return bfs(initial, postsCount);
}
}  // namespace

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int postsCount;
    if (!(std::cin >> postsCount) || postsCount < 1 || postsCount > MAX_DISKS) {
        return 0;
    }

    std::vector<int> posts(postsCount);
    for (int &post : posts) {
        std::cin >> post;
    }

    std::cout << hanoi(postsCount, posts) << '\n';
    return 0;
}

