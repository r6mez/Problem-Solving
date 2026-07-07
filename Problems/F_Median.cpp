// F. Median
// URL: https://codeforces.com/group/zZYq310uLQ/contest/701118/problem/F
// Time: 7/7/2026, 3:32:26 PM
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

vi topologicalSort(int n, vector<vi>& adj, vi& inDeg) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDeg[i] == 0)
            q.push(i);
    }

    vi order;

    while (!q.empty()) {
        int parent = q.front(); q.pop();
        order.push_back(parent);
        for (int child : adj[parent]) {
            if (--inDeg[child] == 0)
                q.push(child);
        }
    }
    
    return order;
}

int dfs(int u, vector<vi>& adj, vi& vis) {
    vis[u] = true;
    int cnt = 1;
    for (int v : adj[u])
        if (!vis[v]) 
            cnt += dfs(v, adj, vis);
    return cnt;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> adj(n + 1), revAdj(n + 1); vi inDeg(n + 1);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
        inDeg[v]++;
    }

    vi topo = topologicalSort(n, adj, inDeg);

    string answer = string(n, '0');
    if(topo.size() < n) finish(answer);

    int half = (n - 1) / 2;
    vi ancestors(n + 1), descendants(n + 1), vis;
    for (int i = 1; i <= n; i++) {
        vis.assign(n + 1, 0);
        descendants[i] = dfs(i, adj, vis) - 1;
        vis.assign(n + 1, 0);
        ancestors[i] = dfs(i, revAdj, vis) - 1;
        if(ancestors[i] <= half && descendants[i] <= half) answer[i - 1] = '1';
    }

    cout << answer << "\n";
}

/*
When is it entirely not valid:
- x x
- x y && y x
- there's a cycle 
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}