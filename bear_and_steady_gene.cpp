#include <array>
#include <iostream>
#include <string>

static inline int idx(char c) {
    switch (c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
        default: return -1;
    }
}

static int steadyGene(const std::string& gene) {
    const int n = static_cast<int>(gene.size());
    const int target = n / 4;

    std::array<int, 4> total{};
    for (char c : gene) {
        ++total[idx(c)];
    }

    std::array<int, 4> need{};
    bool neededAny = false;
    for (int i = 0; i < 4; ++i) {
        if (total[i] > target) {
            need[i] = total[i] - target;
            neededAny = true;
        }
    }

    if (!neededAny) {
        return 0;
    }

    std::array<int, 4> window{};
    int ans = n;
    for (int l = 0, r = 0; r < n; ++r) {
        ++window[idx(gene[r])];
        while (window[0] >= need[0] && window[1] >= need[1] &&
               window[2] >= need[2] && window[3] >= need[3]) {
            ans = std::min(ans, r - l + 1);
            --window[idx(gene[l])];
            ++l;
        }
    }

    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::string gene;
    gene.reserve(n);
    std::cin >> gene;

    std::cout << steadyGene(gene) << '\n';
    return 0;
}

