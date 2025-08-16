/*
    One day, I'm gonna grow wings
*/
// D. Arboris Contractio
// URL: https://codeforces.com/contest/2131/problem/D
// Time: 8/13/2025, 8:17:35 PM
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
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    vector<vi> adj(n + 1);
    vi deg(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    if (n == 2) {
        cout << 0 << '\n';
        return;
    }

    int leaves = 0;
    for (int i = 1; i <= n; ++i)
        if (deg[i] == 1) ++leaves;

    int max_adj_leaves = 0;
    for (int u = 1; u <= n; ++u) {
        int cnt = 0;
        for (int v : adj[u])
            if (deg[v] == 1) ++cnt;
        max_adj_leaves = max(max_adj_leaves, cnt);
    }

    cout << (leaves - max_adj_leaves) << '\n';
}

/*

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}