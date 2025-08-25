/*
    One day, I'm gonna grow wings
*/
// C. Xor-tree
// URL: https://codeforces.com/problemset/problem/430/C
// Time: 8/18/2025, 9:59:26 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> auto& operator<<(auto& o, vector<T>& v) { for (auto& e : v) o << e << ' '; return o; }
template<typename T> auto& operator>>(auto& i, vector<T>& v) { for (auto& e : v) i >> e; return i; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> ini;
vector<int> goal;
vector<int> ans;

void dfs(int i, bool grand_flips, bool flips) {
    if (vis[i]) return;
    vis[i] = true;

    if (goal[i] ^ ini[i] ^ grand_flips) {
        grand_flips ^= 1;
        ans.push_back(i);
    }

    for (auto c : adj[i]) {
        dfs(c, flips, grand_flips);
    }
}

void solve() {
    int n; cin >> n;
    adj.resize(n); vis.resize(n); ini.resize(n); goal.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        cin >> ini[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> goal[i];
    }

    dfs(0, 0, 0);

    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i + 1 << endl;
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