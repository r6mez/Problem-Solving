/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. The End of Happy land
// URL: https://codeforces.com/group/Rilx5irOux/contest/605910/problem/C
// Time: 5/9/2025, 8:32:53 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("happy.in", "r", stdin); }
const int MOD = 1000000007;

void Ramez() {
    int n, x;
    cin >> n >> x;
    vector<vector<int>> adj(n);
    vector<pair<int, int>> edges;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({ u, v });
    }

    auto dfs = [&](auto& dfs, int u, int p, int& diameter) -> int {
        int max1 = 0, max2 = 0;
        for (int v : adj[u]) {
            if (v == p)
                continue;
            int d = dfs(dfs, v, u, diameter) + 1;
            if (d > max1) {
                max2 = max1;
                max1 = d;
            }
            else if (d > max2) {
                max2 = d;
            }
        }
        diameter = max(diameter, max1 + max2);
        return max1;
    };

    int ans = 0;
    for (auto [u, v] : edges) {
        int dm = 0;
        dfs(dfs, u, v, dm);
        if (dm <= x)
            ans++;
        dm = 0;
        dfs(dfs, v, u, dm);
        if (dm <= x)
            ans++;
    }

    int dm = 0;
    dfs(dfs, 0, -1, dm);
    if (dm <= x)
        ans++;

    cout << ans << "\n";
}

/*
NOTES:

*/

int32_t main() {
    UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}