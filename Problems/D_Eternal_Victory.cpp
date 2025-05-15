/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Eternal Victory
// URL: https://codeforces.com/contest/61/problem/D
// Time: 5/12/2025, 11:54:49 PM
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
    vector<vector<pii>> adj(n + 1);
    
    for (int i = 0; i < n - 1; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int sum = 0, maxDis = 0;
    function<void(int, int, int)> dfs = [&](int u, int p, int dist) {
        maxDis = max(maxDis, dist);
        for (auto [v, w] : adj[u]) {
            if (v == p) continue;
            sum += w;
            dfs(v, u, dist + w);
        }
    };

    dfs(1, 0, 0);
    int answer = 2 * sum - maxDis; 
    cout << answer << "\n";
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