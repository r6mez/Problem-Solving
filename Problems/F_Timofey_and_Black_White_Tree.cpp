/*
    One day, I'm gonna grow wings
*/
// F. Timofey and Black-White Tree
// URL: https://codeforces.com/problemset/problem/1790/F
// Time: 9/4/2025, 12:51:01 PM
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
    int n, start; cin >> n >> start;
    vi c(n - 1); cin >> c;
    vector<vi> adj(n + 1);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi dis(n + 1, INT_MAX); 
    int global_dis = INT_MAX;
    
    function<void(int)> bfs = [&](int s) -> void {
        queue<array<int, 3>> q;
        q.push({s, 0, -1});

        while(q.size()){
            auto [u, level, parent] = q.front();
            q.pop();

            dis[u] = level;
            if(level >= global_dis) return;
            
            for(int v : adj[u]){
                if(v == parent) continue;    
                if(level + 1 >= dis[v]) continue;
                q.push({v, level + 1, u});
            }
        }
    };

    bfs(start);

    for (int i = 0; i < n - 1; i++){
        global_dis = min(dis[c[i]], global_dis);
        cout << global_dis << " ";
        if(global_dis != 1) bfs(c[i]);
    }
    cout << "\n";
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