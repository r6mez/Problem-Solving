/*
    One day, I'm gonna grow wings
*/
// D. Lunar New Year and a Wander
// URL: https://codeforces.com/problemset/problem/1106/D
// Time: 8/16/2025, 7:43:30 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> adj(n + 1);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi vis(n + 1);
    
    vi answer;

    priority_queue<int, vi, greater<int>> q;
    q.push(1);
    
    
    while(q.size()){
        int u = q.top(); q.pop();
        if(vis[u]) continue;
        
        vis[u] = true;
        answer.push_back(u);
        
        for(int v : adj[u]){
            q.push(v);
        }
    }

    cout << answer << "\n";
}

/*

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}