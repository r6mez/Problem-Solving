/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Shortest Routes I
// URL: https://cses.fi/problemset/task/1671
// Time: 3/26/2025, 7:36:38 PM
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

// Dijkstra Algorithm
void Ramez() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    vi vis(n + 1), dis(n + 1);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // {cost, node}
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        auto [parentCost, parent] = pq.top(); pq.pop();
        if (vis[parent]) continue;
        vis[parent] = 1; dis[parent] = parentCost;

        for (auto [child, childCost] : adj[parent]) {
            if (!vis[child]) {
                pq.push({ parentCost + childCost, child });
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
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