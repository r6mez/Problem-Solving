/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Path Queries
// URL: https://cses.fi/problemset/task/1138
// Time: 5/4/2025, 9:27:00 PM
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

struct FenwickPUPQ {
    int n;
    vector<int> f;
    FenwickPUPQ(int _n) : n(_n), f(n + 1, 0) {}

    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            f[idx] += val;
    }

    int query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += f[idx];
        return res;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void Ramez() {
    int n, q; cin >> n >> q;
    vi a(n + 1); for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vi> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int MAX = 3 * n;
    vi in(MAX), out(MAX);
    int timer = 1;

    // tree flattening
    function<void(int, int)> dfs = [&](int u, int p) {
        in[u] = timer++;
        for (int v : adj[u]) {
            if(v == p) continue;
            dfs(v, u);
        }
        out[u] = timer++;
    };

    dfs(1, 0);

    FenwickPUPQ tree(MAX);
    
    for (int i = 1; i <= n; i++) {
        tree.update(in[i], a[i]);
        tree.update(out[i], -a[i]);
    }


    while (q--) {
        int ops; cin >> ops;
        if (ops == 1) {
            int s, x; cin >> s >> x;
            // a[s] = x ===> a[s] += x - a[s]
            tree.update(in[s], x - a[s]);
            // -a[s] = -x ===> -a[s] += -x + a[s]
            tree.update(out[s], a[s] - x);
            a[s] = x;
        }
        else {
            int s; cin >> s;
            cout << tree.query(in[s]) << "\n";
        }
    }
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}