/*
    I was alone in an empty universe.
    A universe too small and at the same time... too infinite.
*/
// D. Cleopatra
// URL: https://codeforces.com/group/o09Gu2FpOx/contest/541477/problem/D
// Time: 7/23/2025, 5:42:23 PM
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

vi topologicalSort(int n, vector<vector<pii>>& adj, vi& inDeg) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDeg[i] == 0)
            q.push(i);
    }

    vi order;

    while (!q.empty()) {
        int parent = q.front(); q.pop();
        order.push_back(parent);
        for (auto [child, w] : adj[parent]) {
            if (--inDeg[child] == 0)
                q.push(child);
        }
    }

    return order;
}

void Ramez() {
    int n, m, q; cin >> n >> m >> q;
    vector<vector<pii>> adj(n + 1), jda(n + 1);
    vi inDeg(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        jda[v].push_back({ u, w });
        inDeg[v]++;
    }

    vi topo = topologicalSort(n, adj, inDeg);

    vi to(n + 1, -1), from(n + 1, -1);
    to[1] = 0; from[n] = 0;
    for (int u : topo) {
        if (to[u] == -1) continue;
        for (auto [v, w] : adj[u]) {
            to[v] = max(to[v], to[u] + w);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        int u = topo[i];
        if (from[u] == -1) continue;
        for (auto [v, w] : jda[u]) {
            from[v] = max(from[v], from[u] + w);
        }
    }

    while (q--) {
        int x; cin >> x;
        if (to[x] == -1 || from[x] == -1) {
            cout << "-1\n";
            continue;
        }
        int answer = to[x] + from[x];
        cout << answer << "\n";
    }
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