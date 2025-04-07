/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Flight Discount
// URL: https://cses.fi/problemset/task/1195
// Time: 3/27/2025, 2:07:37 PM
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

// Dijkstra + DP
void Ramez() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    vector<vi> dis(n+1, vi(2, LLONG_MAX));
    dis[1][0] = 0;

    // current cost, current node, coupon used state
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    pq.push({0, 1, 0});    

    while (!pq.empty()) {
        auto [parentCost, parent, used] = pq.top(); pq.pop();
        if (parentCost > dis[parent][used]) continue;

        for (auto [child, childCost] : adj[parent]) {
            // Option 1: Do not use coupon.
            if (dis[child][used] > parentCost + childCost) {
                dis[child][used] = parentCost + childCost;
                pq.push({dis[child][used], child, used});
            }
            
            // Option 2: Use coupon (only if not used before).
            if (!used && dis[child][1] > parentCost + (childCost / 2)) {
                dis[child][1] = parentCost + (childCost / 2);
                pq.push({dis[child][1], child, 1});
            }
        }
    }

    cout << min(dis[n][0], dis[n][1]) << " ";
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