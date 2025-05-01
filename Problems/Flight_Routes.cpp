/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Flight Routes
// URL: https://cses.fi/problemset/task/1196
// Time: 4/24/2025, 10:31:18 AM
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

// K-Dijkstra
void Ramez() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pii>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    vector<vi> dis(n + 1);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // {cost, node}
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        auto [parentCost, parent] = pq.top(); pq.pop();
        if (dis[parent].size() >= k) continue;
        dis[parent].push_back(parentCost);

        for (auto [child, childCost] : adj[parent]) {
            pq.push({ parentCost + childCost, child });
        }
    }

    cout << dis[n] << "\n";
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