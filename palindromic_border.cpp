#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

struct Node {
    int len;
    int link;
    int next[8];
    long long cnt;

    Node() : len(0), link(0), cnt(0) {
        for(int i=0; i<8; ++i) next[i] = 0;
    }
};

Node tree[MAXN + 5];
int num_nodes;
int last_node;
string s;

void init_tree() {
    tree[1].len = -1;
    tree[1].link = 1;
    tree[2].len = 0;
    tree[2].link = 1;
    num_nodes = 2;
    last_node = 2;
}

void extend(int pos) {
    int char_index = s[pos] - 'a';
    int cur = last_node;

    while (true) {
        int len = tree[cur].len;
        if (pos - 1 - len >= 0 && s[pos - 1 - len] == s[pos]) {
            break;
        }
        cur = tree[cur].link;
    }

    if (tree[cur].next[char_index]) {
        last_node = tree[cur].next[char_index];
        tree[last_node].cnt++;
        return;
    }

    int new_node = ++num_nodes;
    tree[new_node].len = tree[cur].len + 2;
    tree[new_node].cnt = 1;
    for(int i=0; i<8; ++i) tree[new_node].next[i] = 0;

    tree[cur].next[char_index] = new_node;

    if (tree[new_node].len == 1) {
        tree[new_node].link = 2;
    } else {
        int temp = tree[cur].link;
        while (true) {
            int len = tree[temp].len;
            if (pos - 1 - len >= 0 && s[pos - 1 - len] == s[pos]) {
                break;
            }
            temp = tree[temp].link;
        }
        tree[new_node].link = tree[temp].next[char_index];
    }

    last_node = new_node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!(cin >> s)) return 0;

    init_tree();
    for (int i = 0; i < s.length(); i++) {
        extend(i);
    }

    for (int i = num_nodes; i > 2; i--) {
        int link = tree[i].link;
        tree[link].cnt += tree[i].cnt;
    }

    long long ans = 0;
    long long inv2 = 500000004; // Modular inverse of 2 modulo 10^9+7

    for (int i = 3; i <= num_nodes; i++) {
        long long c = tree[i].cnt;
        long long pairs = ((c % MOD) * ((c - 1) % MOD)) % MOD;
        pairs = (pairs * inv2) % MOD;
        ans = (ans + pairs) % MOD;
    }

    cout << ans << endl;

    return 0;
}
