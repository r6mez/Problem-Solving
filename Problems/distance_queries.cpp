#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }

// LCA with binary lifting + depth array
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
    int n, q;
    cin >> n >> q;
    vector<vi> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Tree tr(adj, 0);
    // answer queries: dist(a,b) = depth[a] + depth[b] - 2*depth[LCA]
    while (q--) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        int l = tr.LCA(a, b);
        int dist = tr.depth[a] + tr.depth[b] - 2 * tr.depth[l];
        cout << dist << '\n';
    }
}

int32_t main() {
    FastIO();
    Ramez();
    return 0;
}
