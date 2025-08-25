/*
    One day, I'm gonna grow wings
*/
// F. Graph Without Long Directed Paths
// URL: https://codeforces.com/problemset/problem/1144/F
// Time: 8/19/2025, 7:35:26 PM
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
    int n, m; cin >> n >> m;
    vector<vi> adj(n);
    vector<pii> edges(m);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        edges[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vi color(n, -1);
    bool bipartite = true;

    function<void(int, int)> dfsColor = [&](int u, int currColor) -> void { 
        color[u] = currColor;
        for(int v : adj[u]){
            if(color[v] == -1){
                dfsColor(v, !currColor);
            } else if (color[v] == color[u]){
                bipartite = false;
            }
        }
    };

    dfsColor(0, 0);

    if(!bipartite){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < m; i++){
        auto [u, v] = edges[i];
        cout << (color[u] < color[v]);
    }
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