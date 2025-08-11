/*
    I was alone in an empty universe.
    A universe too small and at the same time... too infinite.
*/
// Subtree Queries
// URL: https://cses.fi/problemset/task/1137
// Time: 8/7/2025, 4:29:21 PM
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
const int MOD = 1000000007;

struct FenwickPURQ {
    int n;
    vi f;

    FenwickPURQ(int size) : n(size), f(n + 1, 0) {}

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            f[idx] += val;
    }
    
    int prefix(int idx) const {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += f[idx];
        return res;
    }
    
    int rangeQuery(int l, int r) const {
        return prefix(r) - prefix(l - 1);
    }
};

int n, q;
vector<vi> adj;
vi tin, tout, flat_val, timer;
vi init_val;
FenwickPURQ *fenw;

void dfs(int u, int p) {
    tin[u] = ++timer[0];
    flat_val[timer[0]] = init_val[u];
    for (int v : adj[u]) if (v != p) {
        dfs(v, u);
    }
    tout[u] = timer[0];
}

void Ramez() {
    cin >> n >> q;
    init_val.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> init_val[i];
    adj.assign(n + 1, vi());
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);
    flat_val.assign(n + 1, 0);
    timer.assign(1, 0);
    
    // Flatten tree
    dfs(1, 0);
    
    // Build Fenwick tree
    fenw = new FenwickPURQ(n);
    for (int i = 1; i <= n; i++) {
        fenw->add(i, flat_val[i]);
    }
    
    // Process queries
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            // compute delta
            int idx = tin[s];
            int current = fenw->rangeQuery(idx, idx);
            int delta = x - current;
            fenw->add(idx, delta);
        } else if (type == 2) {
            int s;
            cin >> s;
            int res = fenw->rangeQuery(tin[s], tout[s]);
            cout << res << '\n';
        }
    }
}

int32_t main() {
    FastIO();
    Ramez();
    return 0;
}
