// M. Limit It
// URL: https://codeforces.com/group/Rilx5irOux/contest/678837/problem/M
// Time: 4/22/2026, 5:44:16 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

const int NEG = LLONG_MIN / 4;

int n;
vi a;
vector<vi> g;
vector<vi> dp;
vi sz;
vi f;


struct SegTree {
    typedef int T;
    static constexpr T unit = NEG;
    T f(T a, T b) { return max(a, b); } // (any associative fn)
    vector<T> s; int n;
    SegTree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void dfs(int v, int p) {
    sz[v] = 1;
    dp[v] = {NEG, a[v]};

    for (int c : g[v]) {
        if (c == p) continue;
        dfs(c, v);

        dp[v].resize(sz[v] + sz[c] + 1, NEG);

        for (int k = sz[v]; k >= 1; k--) {
            if (dp[v][k] == NEG) continue;
            for (int j = 1; j <= sz[c]; j++) {
                if (dp[c][j] == NEG) continue;
                dp[v][k + j] = max(dp[v][k + j], dp[v][k] + dp[c][j]);
            }
        }

        sz[v] += sz[c];
    }
}


void solve() {
    cin >> n;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    g.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dp.assign(n + 1, {});
    sz.assign(n + 1, 0);
    dfs(1, 0);

    f.assign(n + 1, NEG);
    for (int v = 1; v <= n; v++)
        for (int k = 1; k < dp[v].size(); k++)
            f[k] = max(f[k], dp[v][k]);

    // segment tree for range max on f[L..R]
    SegTree seg(n + 1);
    for (int i = 1; i <= n; i++) seg.update(i, f[i]);

    int q; cin >> q;
    while (q--) {
        int L, R; cin >> L >> R;
        cout << seg.query(L, R + 1) << "\n";
    }
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}