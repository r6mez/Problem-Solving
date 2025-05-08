/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Apple Tree Traversing
// URL: https://codeforces.com/contest/2107/problem/D
// Time: 5/6/2025, 12:40:12 AM
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
    vector<vi> adj(n + 1);
    vi inDeg(n + 1);
    
    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi vis(n + 1);

    auto dfs = [&](auto &dfs, int u, int p, int dis, vi &parents) -> pii {
        parents[u] = p;  

        pii best = {dis, u};
        for (int v : adj[u]) {
            if (v == p || vis[v]) continue;
            pii curr = dfs(dfs, v, u, dis + 1, parents);
            best = max(best, curr);
        } 

        return best;
    };
    
    vi parents(n + 1), order(n + 1);
    iota(order.begin(), order.end(), 1);
    int ptr = 0;

    
    vector<vi> answer;
    while(true){
        while (ptr < n && vis[order[ptr]]) ptr++;
        if (ptr == n) break;
        int start = order[ptr];

        int u = dfs(dfs, start, 0, 0, parents).second;
        auto [dis, v] = dfs(dfs, u, 0, 0, parents);
        
        int cur = v;
        while (cur != 0 && !vis[cur]) {
            vis[cur] = true;
            cur = parents[cur];
        }
        
        if(u < v) swap(u, v);

        if(dis == 0){
            answer.push_back({1, u, u});
        } else {
            answer.push_back({dis + 1, u, v});
        }
    }
   

    sort(all(answer), greater<>());

    for(vi path : answer) cout << path;
    cout << '\n';
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