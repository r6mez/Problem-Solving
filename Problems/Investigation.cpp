/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Investigation
// URL: https://cses.fi/problemset/task/1202
// Time: 5/8/2025, 6:22:29 PM
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

void Ramez() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    vi dis(n+1, LLONG_MAX), ways(n+1, 0), minF(n+1, LLONG_MAX), maxF(n+1, 0);
    dis[1] = 0; ways[1] = 1; minF[1] = maxF[1] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq; // {cost, node}
    pq.push({ 0, 1 });
    
    while (!pq.empty()) {
        auto [uCost, u] = pq.top(); pq.pop();

        if (uCost > dis[u]) continue;  

        for (auto [v, vCost] : adj[u]) {
            if(uCost + vCost < dis[v]){
                dis[v] = uCost + vCost;
                ways[v] = ways[u];
                minF[v] = minF[u] + 1;
                maxF[v] = maxF[u] + 1;
                pq.push({ uCost + vCost, v });
            } else if (uCost + vCost == dis[v]){
                ways[v] = (ways[v] + ways[u]) % MOD;
                minF[v] = min(minF[v], minF[u] + 1);
                maxF[v] = max(maxF[v], maxF[u] + 1);
            }
        }
    }

    cout << dis[n] << " " << ways[n] << " " << minF[n] << " " << maxF[n];
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