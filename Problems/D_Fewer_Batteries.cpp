/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Fewer Batteries
// URL: https://codeforces.com/problemset/problem/2110/D
// Time: 7/14/2025, 10:51:31 PM
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
    vi b(n + 1); for (int i = 1; i <= n; i++) cin >> b[i];
    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({ v, w });
    }

    auto can = [&](int limit) -> bool {
        vi dp(n + 1, 0);
        for (int u = 1; u <= n; ++u) {
            if (u > 1 && dp[u] == 0) continue;
            dp[u] = min(dp[u] + b[u], limit);
            for (auto [v, w] : adj[u]) {
                if (w <= dp[u]) dp[v] = max(dp[v], dp[u]); // go there at the maximum sum below limit
            }
        }
        return dp.back() > 0;
    };

    int mx = accumulate(all(b), 0LL);

    int l = 0, r = mx + 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (can(mid)) r = mid;
        else l = mid;
    }

    if (r > mx) cout << "-1\n";
    else cout << r << "\n";
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