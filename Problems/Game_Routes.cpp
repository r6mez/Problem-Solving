/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Game Routes
// URL: https://cses.fi/problemset/task/1681
// Time: 5/7/2025, 10:05:26 PM
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
    int n, m; cin >> n >> m;
    vector<vi> adj(n + 1);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    
    vi ways(n + 1, -1);

    function<int(int)> dfs = [&](int u) -> int {
        if(u == n) return 1;
        if(ways[u] != -1) return ways[u];

        int ans = 0;
        for (int v : adj[u]){
            ans = (ans + dfs(v))%MOD;
        }
        
        return ways[u] = ans;
    };

    cout << dfs(1);
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