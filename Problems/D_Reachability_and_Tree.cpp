/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Reachability and Tree
// URL: https://codeforces.com/contest/2112/problem/D
// Time: 6/23/2025, 7:05:01 PM
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

void Ramez() {
    int n; cin >> n;

    vector<vi> adj(n + 1);
    vi deg(n + 1);

    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    function<void(int, int, int)> dfs = [&](int u, int p, int dir)-> void {
        for (auto v : adj[u]) {
            if (v == p) continue;
            if (dir == 1)  cout << v << " " << u << '\n';
            else cout << u << " " << v << '\n';
            dfs(v, u, -dir);
        }
    };

    for (int u = 1; u <= n; u++) {
        if (deg[u] == 2) {
            cout << "YES" << '\n';
            int x = adj[u][0], y = adj[u][1];
            cout << x << " " << u << '\n';
            cout << u << " " << y << '\n';
            dfs(x, u, -1);
            dfs(y, u, 1);
            return;
        }
    }

    cout << "NO" << '\n';
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}