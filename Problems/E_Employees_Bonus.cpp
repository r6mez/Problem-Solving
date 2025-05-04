/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. Employees Bonus
// URL: https://codeforces.com/gym/104375/problem/E
// Time: 5/3/2025, 5:30:46 PM
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

struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int _n) : n(_n), f(n + 1, 0) {}
    void update(int idx, int v) {
        for (; idx <= n; idx += idx & -idx) f[idx] += v;
    }
    int query(int idx) {
        int s = 0;
        for (; idx > 0; idx -= idx & -idx) s += f[idx];
        return s;
    }
    void rangeAdd(int l, int r, int v) {
        update(l, v);
        if (r + 1 <= n) update(r + 1, -v);
    }
    int pointQuery(int idx) {
        return query(idx);
    }
};

void Ramez() {
    int N, Q; cin >> N >> Q;
    vi a(N + 1); for (int i = 1; i <= N; i++) cin >> a[i];

    vector<vi> adj(N + 1);
    vi inDeg(N + 1, 0);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDeg[v]++;
    }

    int root = 1;
    for (int i = 1; i <= N; i++) {
        if (inDeg[i] == 0) { root = i; break; }
    }

    vi tin(N + 1), subsz(N + 1);
    int timer = 0;

    function<void(int)> dfs = [&](int u) -> void {
        tin[u] = ++timer;
        subsz[u] = 1;
        for (int v : adj[u]) {
            dfs(v);
            subsz[u] += subsz[v];
        }
    };

    dfs(root);    // Euler‐tour flatten

    // read bonuses and precompute q[j], r[j]
    vi X(Q + 1), B(Q + 1), Qv(Q + 1), Rm(Q + 1);
    for (int j = 1; j <= Q; j++) {
        cin >> X[j] >> B[j];
        int S = subsz[X[j]];
        Qv[j] = B[j] / S;
        Rm[j] = B[j] % S;
    }

    vi lo(N + 1, 1), hi(N + 1, Q + 1), ans(N + 1, -1);
    vector<vi> bucket(Q + 2);

    bool changed = true;
    while (changed) {
        changed = false;

        // clear buckets
        for (int j = 1; j <= Q; j++) bucket[j].clear();

        // assign employees to mid‐buckets
        for (int i = 1; i <= N; i++) {
            if (lo[i] < hi[i]) {
                changed = true; // there's still room for search for any employee
                int mid = (lo[i] + hi[i]) / 2;
                bucket[mid].push_back(i);
            }
        }

        if (!changed) break;

        Fenwick bit(N);

        // sweep bonuses 1..Q
        for (int j = 1; j <= Q; j++) {
            // apply bonus j to employee x and it's subtree
            int x = X[j];
            bit.rangeAdd(tin[x], tin[x] + subsz[x] - 1, Qv[j]); // they get the split
            bit.rangeAdd(tin[x], tin[x], Rm[j]); // he gets the rem

            // We only look at those employees that we previously decided to test at mid = j. They’re in bucket[j].
            for (int i : bucket[j]) {
                int got = bit.pointQuery(tin[i]);
                if (got >= a[i]) hi[i] = j;
                else lo[i] = j + 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (lo[i] <= Q) ans[i] = lo[i];
        else ans[i] = -1;
        cout << ans[i] << "\n";
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