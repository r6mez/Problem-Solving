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

    vi dis(n + 1, 0), parent(n + 1, -1);

   
    // Relaxation (n - 1) times
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auto [u, v, w] = edges[j];
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                parent[v] = u;
            }
        }
    }

    // if any edge can still be relaxed, that means there's a cycle
    int x = -1;
    for (int i = 0; i < m; i++){
        auto [u, v, w] = edges[i];
        if (dis[v] > dis[u] + w) {
            dis[v] = dis[u] + w;
            parent[v] = u;
            x = v;
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return;
    }


    // x is a vertex that was relaxed in the nth iteration.
   // To ensure we are inside the cycle, move n steps from x
   int y = x;
   for (int i = 0; i < n; i++) {
       y = parent[y];
   }

   // Reconstruct the cycle
   vector<int> cycle;
   int curr = y;
   do {
       cycle.push_back(curr);
       curr = parent[curr];
   } while (curr != y);
   cycle.push_back(y);
   reverse(all(cycle));

   cout << "YES\n" << cycle;
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