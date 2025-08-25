/*
    One day, I'm gonna grow wings
*/
// E1. Escape The Maze (easy version)
// URL: https://codeforces.com/problemset/problem/1611/E1
// Time: 8/23/2025, 12:22:10 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> auto& operator<<(auto& o, vector<T>& v) { for (auto& e : v) o << e << ' '; return o; }
template<typename T> auto& operator>>(auto& i, vector<T>& v) { for (auto& e : v) i >> e; return i; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void solve() {
    int n, k; cin >> n >> k;
    vector<vi> adj(n);
    vi x(k); cin >> x;
    vi inDeg(n);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
        inDeg[u]++; inDeg[v]++;
    }

    vi mark(n);
    queue<int> q;
    
    mark[0] = 1;
    for (int i = 0; i < k; i++){
        x[i]--;
        mark[x[i]] = -1;
        q.push(x[i]);
    }
    q.push(0);
    
     while(q.size()){
        int u = q.front(); q.pop();

        if(u != 0 && mark[u] == 1 && inDeg[u] == 1){
            cout << "YES\n";
            return;
        }
        
        for(int v : adj[u]){
            if(mark[v]) continue;
            mark[v] = mark[u];
            q.push(v);
        }    
    }
    
    cout << "NO\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}