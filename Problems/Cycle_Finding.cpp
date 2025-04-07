/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Cycle Finding
// URL: https://cses.fi/problemset/task/1197
// Time: 3/27/2025, 3:43:54 PM
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

struct edge {
    int u, v, w;
};

// Bellman-Ford Algorithm (Negative Cycles Detection)
void Ramez() {
    int n, m; cin >> n >> m;

    vector<edge> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({ u, v, w });
    }

    // Initialize distances for all nodes to 0 to detect cycles in any component.
    const int INF = 1e18;
    vi dist(n + 1, 0), parent(n + 1, -1);

    int x = -1;
    // Relax edges n times.
    for (int i = 0; i < n; i++) {
        x = -1;
        for (int j = 0; j < m; j++) {
            auto [u, v, w] = edges[j];
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    }
    else {
        // x is a vertex that was relaxed in the nth iteration.
        // Walk back n times to ensure we are on a cycle.
        int y = x;
        for (int i = 0; i < n; i++) {
            y = parent[y];
        }

        // Reconstruct the cycle.
        vector<int> cycle;
        for (int cur = y;; cur = parent[cur]) {
            cycle.push_back(cur);
            if (cur == y && cycle.size() > 1) break;
        }

        reverse(all(cycle));

        cout << "YES\n";
        cout << cycle << "\n";
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