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
    vi  g(n + 1), sub(n + 1); 
    for (int i = 1; i <= n; i++){
        cin >> g[i];
    }
    
    vector<vi> adj(n + 1);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    
    function<void(int)> dfs = [&](int u) -> void {
        sub[u] = 1;
        for(int v : adj[u]){
            dfs(v);
            sub[u] += sub[v];
            g[u] = gcd(g[u], g[v]);
        }
    };

    cout << g << "\n";

    dfs(1);

    cout << g << "\n";
    cout << sub << "\n";

    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(ans, g[i] * sub[i]);
    }

    cout << ans << "\n";
}

/*

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}