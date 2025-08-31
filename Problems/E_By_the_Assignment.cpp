/*
    One day, I'm gonna grow wings
*/
// E. By the Assignment
// URL: https://codeforces.com/contest/2136/problem/E
// Time: 8/30/2025, 2:47:03 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 998244353;

int mul(int a, int b) {
    a %= MOD;
    b %= MOD;
    return (a * b) % MOD;
}


void solve() {
    int n, m, V;
    cin >> n >> m >> V;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<pair<int, int> > > g(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y, i);
        g[y].emplace_back(x, i);
    }
    vector<int> tin(n, -1), fup(n, -1);
    vector<bool> bridge(m, false);
    int timer = 0;
    function<void(int, int)> dfs = [&](int v, int anc) {
        tin[v] = fup[v] = ++timer;
        for (auto [to, id] : g[v]) {
            if (to == anc) continue;
            if (tin[to] == -1) {
                dfs(to, v);
                fup[v] = min(fup[v], fup[to]);
                if (fup[to] > tin[v]) {
                    bridge[id] = true;
                }
            }
            else {
                fup[v] = min(fup[v], tin[to]);
            }
        }
        };
    dfs(0, -1);
    vector<int> comp(n, -1), col(n, -1);
    int cmp = 0;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (comp[i] == -1) {
            queue<int> q;
            comp[i] = cmp;
            col[i] = 0;
            q.push(i);
            bool ok = true;
            bool have = false;
            int need = -1;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                if (a[v] != -1) {
                    if (!have) {
                        have = true;
                        need = a[v];
                    }
                    else if (need != a[v]) {
                        cout << "0\n";
                        return;
                    }
                }
                for (auto [to, id] : g[v]) {
                    if (bridge[id]) continue;
                    if (comp[to] == -1) {
                        comp[to] = cmp;
                        col[to] = col[v] ^ 1;
                        q.push(to);
                    }
                    else {
                        if (col[to] == col[v]) {
                            ok = false;
                        }
                    }
                }
            }
            if (!ok) {
                if (have && need != 0) { cout << 0 << '\n'; return; }
            }
            else {
                if (!have) ans = mul(ans, V);
            }
            cmp++;
        }
    }
    cout << ans << '\n';
}
/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}