/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Planets Queries I
// URL: https://cses.fi/problemset/task/1750
// Time: 5/8/2025, 8:45:09 PM
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
    int n, q; cin >> n >> q;
    vi a(n + 1); for (int i = 1; i <= n; i++) cin >> a[i];
    
    vector<vi> paths(n + 1);

    function<void(int, int, vi&)> dfs = [&](int u, int start, vi &vis) -> void {
        if(vis[u]) return;
        vis[u] = true;
        paths[start].push_back(u);
        dfs(a[u], start, vis);
    };

    for (int start = 1; start <= n; start++){
        // for each node find its cycle
        vi vis(n + 1);
        dfs(start, start, vis);
    }
    
    while(q--){
        int x, k; cin >> x >> k;
        int sz = paths[x].size();

        int answer = (k < sz ? paths[x][k] : paths[x][k % sz]);
        cout << answer << "\n";
    }
}

/*
NOTES:
1 2
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}