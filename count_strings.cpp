#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>

using namespace std;

long long MOD = 1000000007;

struct NFAContext {
    vector<vector<pair<int, char>>> adj;
    int node_count = 0;

    void clear() {
        adj.clear();
        node_count = 0;
    }

    int new_node() {
        adj.push_back({});
        return node_count++;
    }

    void add_edge(int u, int v, char c) {
        adj[u].push_back({v, c});
    }
};

NFAContext ctx;

struct NFAFragment {
    int start;
    int end;
};

NFAFragment parse(string s) {
    if (s == "a") {
        int u = ctx.new_node();
        int v = ctx.new_node();
        ctx.add_edge(u, v, 'a');
        return {u, v};
    }
    if (s == "b") {
        int u = ctx.new_node();
        int v = ctx.new_node();
        ctx.add_edge(u, v, 'b');
        return {u, v};
    }
    if (s == "") {
        int u = ctx.new_node();
        int v = ctx.new_node();
        ctx.add_edge(u, v, 'e');
        return {u, v};
    }

    bool wrapped = false;
    if (s.size() >= 2 && s.front() == '(' && s.back() == ')') {
        int bal = 0;
        bool match = true;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '(') bal++;
            else if (s[i] == ')') bal--;
            if (bal == 0) {
                match = false;
                break;
            }
        }
        if (match) {
            return parse(s.substr(1, s.size() - 2));
        }
    }

    if (s.back() == '*') {
         NFAFragment inner = parse(s.substr(0, s.size() - 1));
         int start = ctx.new_node();
         int end = ctx.new_node();
         ctx.add_edge(start, inner.start, 'e');
         ctx.add_edge(inner.end, end, 'e');
         ctx.add_edge(inner.end, inner.start, 'e');
         ctx.add_edge(start, end, 'e');
         return {start, end};
    }

    int bal = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') bal++;
        else if (s[i] == ')') bal--;
        else if (s[i] == '|' && bal == 0) {
             NFAFragment f1 = parse(s.substr(0, i));
             NFAFragment f2 = parse(s.substr(i + 1));
             int start = ctx.new_node();
             int end = ctx.new_node();
             ctx.add_edge(start, f1.start, 'e');
             ctx.add_edge(start, f2.start, 'e');
             ctx.add_edge(f1.end, end, 'e');
             ctx.add_edge(f2.end, end, 'e');
             return {start, end};
        }
    }

    int k = 0;
    if (s[0] == '(') {
        bal = 1;
        k = 1;
        while (bal > 0 && k < s.size()) {
             if (s[k] == '(') bal++;
             else if (s[k] == ')') bal--;
             k++;
        }
    } else {
        k = 1;
    }

    string left = s.substr(0, k);
    string right = s.substr(k);

    NFAFragment f1 = parse(left);
    NFAFragment f2 = parse(right);
    ctx.add_edge(f1.end, f2.start, 'e');
    return {f1.start, f2.end};
}

void get_epsilon_closure(int u, set<int>& closure, vector<bool>& visited) {
    if (visited[u]) return;
    visited[u] = true;
    closure.insert(u);
    for (auto& edge : ctx.adj[u]) {
        if (edge.second == 'e') {
            get_epsilon_closure(edge.first, closure, visited);
        }
    }
}

set<int> get_closure(const set<int>& states) {
    set<int> closure;
    vector<bool> visited(ctx.node_count, false);
    for (int u : states) {
        get_epsilon_closure(u, closure, visited);
    }
    return closure;
}

set<int> move_set(const set<int>& states, char c) {
    set<int> next;
    for (int u : states) {
        for (auto& edge : ctx.adj[u]) {
            if (edge.second == c) {
                next.insert(edge.first);
            }
        }
    }
    return next;
}

typedef vector<vector<long long>> Matrix;

Matrix multiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < n; j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix power(Matrix A, long long p) {
    int n = A.size();
    Matrix Res(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) Res[i][i] = 1;
    while (p > 0) {
        if (p & 1) Res = multiply(Res, A);
        A = multiply(A, A);
        p >>= 1;
    }
    return Res;
}

void solve() {
    string regex;
    long long L;
    cin >> regex >> L;

    ctx.clear();
    NFAFragment root = parse(regex);

    map<set<int>, int> state_map;
    vector<set<int>> dfa_states;
    queue<int> q;

    set<int> initial;
    initial.insert(root.start);
    set<int> start_closure = get_closure(initial);

    state_map[start_closure] = 0;
    dfa_states.push_back(start_closure);
    q.push(0);

    vector<pair<int, int>> transitions;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for (char c : {'a', 'b'}) {
            set<int> next_raw = move_set(dfa_states[u], c);
            if (next_raw.empty()) continue;

            set<int> next_closure = get_closure(next_raw);
            if (next_closure.empty()) continue;

            if (state_map.find(next_closure) == state_map.end()) {
                state_map[next_closure] = dfa_states.size();
                dfa_states.push_back(next_closure);
                q.push(state_map[next_closure]);
            }

            int v = state_map[next_closure];
            transitions.push_back({u, v});
        }
    }

    int n = dfa_states.size();
    Matrix M(n, vector<long long>(n, 0));
    for (auto& p : transitions) {
        M[p.first][p.second]++;
    }

    Matrix Res = power(M, L);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (dfa_states[i].count(root.end)) {
            ans = (ans + Res[0][i]) % MOD;
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
