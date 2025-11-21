#include <iostream>
#include <vector>
#include <queue>
#include <string>

namespace {
constexpr int kMoves = 6;
constexpr int DR[kMoves] = {-2, -2, 0, 2, 2, 0};
constexpr int DC[kMoves] = {-1, 1, 2, 1, -1, -2};
constexpr const char *MOVE_NAMES[kMoves] = {"UL", "UR", "R", "LR", "LL", "L"};

struct Cell {
    int r;
    int c;
};
}  // namespace

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    int r_start, c_start, r_end, c_end;
    if (!(std::cin >> r_start >> c_start >> r_end >> c_end)) {
        return 0;
    }

    if (r_start == r_end && c_start == c_end) {
        std::cout << 0 << "\n\n";
        return 0;
    }

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
    std::vector<std::vector<int>> parent_move(n, std::vector<int>(n, -1));
    std::vector<std::vector<Cell>> parent(n, std::vector<Cell>(n));

    std::queue<Cell> q;
    q.push({r_start, c_start});
    visited[r_start][c_start] = true;

    bool found = false;
    while (!q.empty()) {
        const Cell current = q.front();
        q.pop();

        if (current.r == r_end && current.c == c_end) {
            found = true;
            break;
        }

        for (int move = 0; move < kMoves; ++move) {
            int nr = current.r + DR[move];
            int nc = current.c + DC[move];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                continue;
            }
            if (visited[nr][nc]) {
                continue;
            }
            visited[nr][nc] = true;
            parent_move[nr][nc] = move;
            parent[nr][nc] = current;
            q.push({nr, nc});
        }
    }

    if (!found) {
        std::cout << "Impossible\n";
        return 0;
    }

    std::vector<std::string> path;
    int r = r_end;
    int c = c_end;
    while (parent_move[r][c] != -1) {
        int move = parent_move[r][c];
        path.push_back(MOVE_NAMES[move]);
        Cell previous = parent[r][c];
        r = previous.r;
        c = previous.c;
    }

    std::cout << path.size() << '\n';
    for (auto it = path.rbegin(); it != path.rend(); ++it) {
        if (it != path.rbegin()) {
            std::cout << ' ';
        }
        std::cout << *it;
    }
    std::cout << '\n';

    return 0;
}

