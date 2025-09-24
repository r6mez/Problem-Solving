/*
    One day, I'm gonna grow wings
*/
// C. Max Tree
// URL: https://codeforces.com/contest/2143/problem/C
// Time: 9/17/2025, 6:04:31 PM
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

void solve() {
    int n; cin >> n;
    vector<vi> adj(n + 1);
    vi indeg(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, x, y; cin >> u >> v >> x >> y;
        if (x > y) {
            adj[u].push_back(v);
            indeg[v]++;
        } else {
            adj[v].push_back(u);
            indeg[u]++;
        }
    }

    vi order = topologicalSort(n, adj, indeg);

    vi p(n);
    int curr = n;
    for (int i = 0; i < n; i++){
        p[order[i] - 1] = curr;
        curr--;
    }

    cout << p << "\n";
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