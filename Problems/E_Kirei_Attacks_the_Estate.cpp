/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. Kirei Attacks the Estate
// URL: https://codeforces.com/contest/2114/problem/E
// Time: 5/26/2025, 6:57:26 PM
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
    vi a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    vector<vi> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi answer(n + 1);
    auto dfs = [&](auto self, int u, int level, int sum, int minSum, int maxSum) -> void {
            int newSum = sum + ((level % 2 == 0 ? +1 : -1) * a[u]);
            if (level & 1) answer[u] = maxSum - newSum;
            else answer[u] = newSum - minSum;
            
            for (int v : adj[u]) {
                if (answer[v]) continue;
                self(self, v, level + 1, newSum, min(minSum, newSum),  max(maxSum, newSum));
            }
    };

    dfs(dfs, 1, 0, 0, 0, 0);

    for (int i = 1; i <= n; i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";
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