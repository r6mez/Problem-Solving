/*
    I was alone in an empty universe.
    A universe too small and at the same time... too infinite.
*/
// Counting Paths
// URL: https://cses.fi/problemset/task/1136
// Time: 8/7/2025, 3:25:33 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }

struct Tree {
    int n, LOG;
    vi depth;
    vector<vi> up;

    Tree(const vector<vi>& adj, int root = 0) {
        n = adj.size();
        LOG = ceil(log2(n));
        depth.assign(n, 0);
        up.assign(LOG + 1, vi(n, -1));

        dfs(adj, root, root);
        for (int k = 1; k <= LOG; ++k) {
            for (int v = 0; v < n; ++v) {
                int p = up[k - 1][v];
                up[k][v] = (p < 0 ? -1 : up[k - 1][p]);
            }
        }
    }

    void dfs(const vector<vi>& adj, int v, int parent) {
        up[0][v] = parent;
        for (int u : adj[v]) {
            if (u == parent) continue;
            depth[u] = depth[v] + 1;
            dfs(adj, u, v);
        }
    }

    int kth_ancestor(int v, int dist) const {
        for (int k = 0; dist && v >= 0; ++k) {
            if (dist & 1) v = up[k][v];
            dist >>= 1;
        }
        return v;
    }

    int LCA(int a, int b) const {
        if (depth[a] < depth[b]) swap(a, b);
        a = kth_ancestor(a, depth[a] - depth[b]);
        if (a == b) return a;
        for (int k = LOG; k >= 0; --k) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }
        return up[0][a];
    }
};

void Ramez() {
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Tree tr(adj, 0);
    vi sub(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        int l = tr.LCA(a, b);
        sub[a]++;
        sub[b]++;
        sub[l]--;
        if (l != 0) sub[tr.up[0][l]]--;
    }

    // accumulate differences bottom-up
    function<void(int,int)> dfs2 = [&](int u, int p) {
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs2(v, u);
            sub[u] += sub[v];
        }
    };
    dfs2(0, -1);

    for (int i = 0; i < n; i++) {
        cout << sub[i] << (i + 1 == n ? '\n' : ' ');
    }
}

int32_t main() {
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}