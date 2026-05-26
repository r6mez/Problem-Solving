// I. The Distributed Compiler Pipeline
// URL: https://codeforces.com/group/Rilx5irOux/contest/686782/problem/I
// Time: 5/25/2026, 5:06:46 PM
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

//A topological sort takes a directed acyclic graph (DAG) and produces 
//a linear ordering of its vertices such that for every directed edge
// u → v, u comes before v in that order.
// Returns a vector of nodes in a valid order; if a cycle exists, the size will be < n. 
// useful for: Scheduling with Dependencies, Course Prerequisites, 


void solve() {
    int n ,m ; cin >> n >> m;
    vector<pii>jobs(n);
    vector<vi>adj(m);
    vi inDeg(n);
    for(int i =0 , u ,v ;i < m ;++i)
    {
        cin >> u >> v ;
        adj[u].push_back(v);
        inDeg[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDeg[i] == 0)
            q.push(i);
    }

    vector<pii>order(n);
    vector<bool>vis(n);
    while (!q.empty()) {
        int parent = q.front(); q.pop();
        for (int child : adj[parent]) {
            --inDeg[child] ;
            if (inDeg[child] == 0)
            {
                
                q.push(child);
                vis[child] = true ; 
            }
        }
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