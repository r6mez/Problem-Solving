/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Round Trip
// URL: https://cses.fi/problemset/task/1669
// Time: 5/8/2025, 1:52:13 AM
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
    vector<vi> adj(n + 1);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi vis(n + 1, 0), parent(n + 1 , -1);
    int start = -1, end = -1;

    function<bool(int, int)> dfs = [&](int u, int p) -> bool {
        vis[u] = true;
        parent[u] = p;

        for(int v : adj[u]){
            if(v == p) continue;
            
            if(vis[v]){
                start = v;
                end  = u;
                return true;
            } 

            if(dfs(v, u)) return true;
        }

        return false;
    };

    int found = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && dfs(i, -1)) {
            found = true;
            break;
        }
    }
    
    if(!found){
        cout << "IMPOSSIBLE";
        return;
    }
    
    vi path;
    path.push_back(start);
    for (int x = end; x != start; x = parent[x]) path.push_back(x);
    path.push_back(start);

    cout << path.size() << "\n" << path;
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