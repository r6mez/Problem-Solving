/*
    One day, I'm gonna grow wings
*/
// C. Mail Stamps
// URL: https://codeforces.com/problemset/problem/29/C
// Time: 11/7/2025, 4:59:00 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;



void solve() {
    int n; cin >> n;
    map<int, vi> adj;
    for (int i = 0; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start = -1;
    for(auto [u, children] : adj){
        if(children.size() == 1) {
            start = u;
        }
    }
    
    vi path;

    function<void(int, int)> dfs = [&](int u, int p) -> void {
        path.push_back(u);
        for(int v : adj[u]){
            if(v == p) continue;
            dfs(v, u);
        }
    };
    
    dfs(start, -1);

    cout << path;
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