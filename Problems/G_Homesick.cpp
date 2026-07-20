// G. Homesick
// URL: https://codeforces.com/group/zZYq310uLQ/contest/700325/problem/G
// Time: 7/20/2026, 5:38:23 PM
#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n + 1);   // (neighbor, directedEdgeId)
    vi headOf(2 * m);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back({v, 2 * i});
        adj[v].push_back({u, 2 * i + 1});
        headOf[2 * i]     = v;
        headOf[2 * i + 1] = u;
    }

    vi par(2 * m, -2);
    vector<char> vis(2 * m, 0);
    vector<char> arrivals(n + 1, 0);  // 0, 1, or 2 = times vertex expanded
    vi skipped(n + 1, -1);            // out-edge deferred after first expansion
    queue<int> q;                              // edge ids; vertex = headOf[edge]

    for (auto [w, de] : adj[1])
        if (!vis[de]) { vis[de] = 1; par[de] = -1; q.push(de); }

    int goal = -1;
    while (!q.empty()) {
        int e = q.front(); q.pop();
        int y = headOf[e];
        if (y == 1) { goal = e; break; }

        if (arrivals[y] == 0) {
            arrivals[y] = 1;
            skipped[y] = e ^ 1;                    // the deferred out-edge
            for (auto [z, f] : adj[y]) {
                if (f == (e ^ 1)) continue;        // no immediate backtrack
                if (vis[f]) continue;
                vis[f] = 1; par[f] = e; q.push(f);
            }
        } else if (arrivals[y] == 1) {
            arrivals[y] = 2;
            int f = skipped[y];
            if (f != -1 && !vis[f]) { vis[f] = 1; par[f] = e; q.push(f); }
        }
    }

    if (goal == -1) finish("impossible");

    vi answer;
    for (int e = goal; e != -1; e = par[e])
        answer.push_back(headOf[e]);
    answer.push_back(1);
    reverse(all(answer));

    cout << answer.size() << "\n" << answer << "\n";
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