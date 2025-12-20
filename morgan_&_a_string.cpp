#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Suffix Array implementation using cyclic shifts
vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);

    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                classes++;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return c;
}

string solve() {
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    string s = a + '{' + b + '{'; // '{' is ascii 123, > 'Z'
    vector<int> rank = sort_cyclic_shifts(s);

    string res = "";
    res.reserve(n + m);
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (rank[i] < rank[n + 1 + j]) {
            res += a[i++];
        } else {
            res += b[j++];
        }
    }
    while (i < n) res += a[i++];
    while (j < m) res += b[j++];

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            cout << solve() << endl;
        }
    }
    return 0;
}

