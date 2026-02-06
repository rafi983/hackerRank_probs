#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXLEN = 200005;
const int ALPHABET = 26;

struct SAM {
    struct State {
        int len, link;
        int next[ALPHABET];
        long long count;
        bool visited;
    } st[MAXLEN * 2];

    int sz, last;

    void init() {
        st[0].len = 0;
        st[0].link = -1;
        memset(st[0].next, -1, sizeof(st[0].next));
        st[0].count = 0;
        st[0].visited = false;
        sz = 1;
        last = 0;
    }

    void extend(char c_char) {
        int c = c_char - 'a';
        int p = last;

        if (st[p].next[c] != -1) {
            int q = st[p].next[c];
            if (st[q].len == st[p].len + 1) {
                last = q;
            } else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
                st[clone].link = st[q].link;
                st[clone].count = 0;
                st[clone].visited = false;

                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = clone;
                last = clone;
            }
            return;
        }

        int cur = sz++;
        st[cur].len = st[p].len + 1;
        memset(st[cur].next, -1, sizeof(st[cur].next));
        st[cur].count = 0;
        st[cur].visited = false;

        while (p != -1 && st[p].next[c] == -1) {
            st[p].next[c] = cur;
            p = st[p].link;
        }

        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
                st[clone].link = st[q].link;
                st[clone].count = 0;
                st[clone].visited = false;

                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = clone;
                st[cur].link = clone;
            }
        }
        last = cur;
    }

    void reset_last() {
        last = 0;
    }

    long long calc_count(int u) {
        if (st[u].visited) return st[u].count;
        st[u].count = 1;
        for (int i = 0; i < ALPHABET; ++i) {
            if (st[u].next[i] != -1) {
                st[u].count += calc_count(st[u].next[i]);
            }
        }
        st[u].visited = true;
        return st[u].count;
    }

    void build_counts() {
        calc_count(0);
    }

    string find_kth(long long k) {
        if (k > st[0].count - 1) return "INVALID";

        string res = "";
        int u = 0;
        while (k > 0) {
            for (int i = 0; i < ALPHABET; ++i) {
                int v = st[u].next[i];
                if (v != -1) {
                    long long cnt = st[v].count;
                    if (k <= cnt) {
                        res += (char)('a' + i);
                        u = v;
                        k--;
                        if (k == 0) return res;
                        goto next_char_found;
                    } else {
                        k -= cnt;
                    }
                }
            }
            return "INVALID";
            next_char_found:;
        }
        return res;
    }
} sam;

vector<string> findStrings(vector<string> w, vector<int> queries) {
    sam.init();
    for (const string& s : w) {
        sam.reset_last();
        for (char c : s) {
            sam.extend(c);
        }
    }
    sam.build_counts();

    vector<string> results;
    for (int k : queries) {
        results.push_back(sam.find_kth(k));
    }
    return results;
}

int main() {
    int n;
    if (cin >> n) {
        vector<string> w(n);
        for (int i = 0; i < n; ++i) {
            cin >> w[i];
        }
        int q;
        cin >> q;
        vector<int> queries(q);
        for (int i = 0; i < q; ++i) {
            cin >> queries[i];
        }

        vector<string> ans = findStrings(w, queries);
        for (const string& s : ans) {
            cout << s << endl;
        }
    }
    return 0;
}
