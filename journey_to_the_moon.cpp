#include <iostream>
#include <vector>

class DisjointSet {
public:
    explicit DisjointSet(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) {
            return;
        }
        if (size[rootA] < size[rootB]) {
            std::swap(rootA, rootB);
        }
        parent[rootB] = rootA;
        size[rootA] += size[rootB];
    }

    const std::vector<int> &getSizes() const {
        return size;
    }

    const std::vector<int> &getParents() const {
        return parent;
    }

private:
    std::vector<int> parent;
    std::vector<int> size;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, p;
    if (!(std::cin >> n >> p)) {
        return 0;
    }

    DisjointSet dsu(n);
    for (int i = 0; i < p; ++i) {
        int a, b;
        std::cin >> a >> b;
        dsu.unite(a, b);
    }

    const auto &parent = dsu.getParents();
    const auto &sizes = dsu.getSizes();

    long long result = 0;
    long long remaining = n;
    for (int i = 0; i < n; ++i) {
        if (parent[i] == i) {
            long long componentSize = sizes[i];
            remaining -= componentSize;
            result += componentSize * remaining;
        }
    }

    std::cout << result << '\n';
    return 0;
}

