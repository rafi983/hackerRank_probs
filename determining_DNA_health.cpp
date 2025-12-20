#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 2000005; // Max total length of genes
const int SIGMA = 26;

int trie[MAXN][SIGMA];
int fail[MAXN];
int nodes_count = 1;
vector<int> gene_node_indices; // Maps gene index to trie node

// Failure tree
vector<int> adj[MAXN];
int in_time[MAXN], out_time[MAXN];
int timer = 0;

// BIT
long long bit[MAXN];
int max_timer = 0;

void update(int idx, long long val) {
    for (; idx <= max_timer; idx += idx & -idx)
        bit[idx] += val;
}

long long query(int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}

void insert_gene(const string& s, int gene_idx) {
    int u = 0;
    for (char c : s) {
        int v = c - 'a';
        if (!trie[u][v]) {
            trie[u][v] = nodes_count++;
        }
        u = trie[u][v];
    }
    gene_node_indices.push_back(u);
}

void build_ac() {
    queue<int> q;
    for (int i = 0; i < SIGMA; ++i) {
        if (trie[0][i]) {
            q.push(trie[0][i]);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < SIGMA; ++i) {
            if (trie[u][i]) {
                fail[trie[u][i]] = trie[fail[u]][i];
                q.push(trie[u][i]);
            } else {
                trie[u][i] = trie[fail[u]][i];
            }
        }
    }
}

void dfs_fail_tree(int u) {
    in_time[u] = ++timer;
    for (int v : adj[u]) {
        dfs_fail_tree(v);
    }
    out_time[u] = timer;
}

struct Query {
    int id;
    int l, r;
    string d;
    long long total_health;
};

struct Event {
    int time; // gene index
    int type; // 0 for query part (subtract), 1 for query part (add)
    int query_index;
};

bool compareEvents(const Event& a, const Event& b) {
    return a.time < b.time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> genes(n);
    for (int i = 0; i < n; ++i) cin >> genes[i];

    vector<int> healths(n);
    for (int i = 0; i < n; ++i) cin >> healths[i];

    // Build Trie
    for (int i = 0; i < n; ++i) {
        insert_gene(genes[i], i);
    }

    // Build AC
    build_ac();

    // Build Failure Tree
    for (int i = 1; i < nodes_count; ++i) {
        adj[fail[i]].push_back(i);
    }
    dfs_fail_tree(0);
    max_timer = timer;

    int s;
    cin >> s;
    vector<Query> queries(s);
    vector<Event> events;

    for (int i = 0; i < s; ++i) {
        queries[i].id = i;
        queries[i].total_health = 0;
        cin >> queries[i].l >> queries[i].r >> queries[i].d;

        // Query is sum(0 to r) - sum(0 to l-1)
        events.push_back({queries[i].r, 1, i});
        if (queries[i].l > 0) {
            events.push_back({queries[i].l - 1, -1, i});
        }
    }

    sort(events.begin(), events.end(), compareEvents);

    int event_idx = 0;
    for (int i = 0; i < n; ++i) {
        // Activate gene i
        int u = gene_node_indices[i];
        // Range update on subtree of u in failure tree
        update(in_time[u], healths[i]);
        update(out_time[u] + 1, -healths[i]);

        // Process events ending at i
        while (event_idx < events.size() && events[event_idx].time == i) {
            int q_idx = events[event_idx].query_index;
            int type = events[event_idx].type; // 1 or -1

            long long current_val = 0;
            int curr = 0;
            for (char c : queries[q_idx].d) {
                curr = trie[curr][c - 'a'];
                current_val += query(in_time[curr]);
            }

            if (type == 1) queries[q_idx].total_health += current_val;
            else queries[q_idx].total_health -= current_val;

            event_idx++;
        }
    }

    long long min_health = -1;
    long long max_health = -1;
    bool first = true;

    for (int i = 0; i < s; ++i) {
        if (first) {
            min_health = queries[i].total_health;
            max_health = queries[i].total_health;
            first = false;
        } else {
            min_health = min(min_health, queries[i].total_health);
            max_health = max(max_health, queries[i].total_health);
        }
    }

    cout << min_health << " " << max_health << endl;

    return 0;
}

