/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// I. Strongly Connected
// URL: https://codeforces.com/group/Rilx5irOux/contest/607176/problem/I
// Time: 5/21/2025, 5:17:30 PM
#include <bits/stdc++.h>
using namespace std;
#define ll    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;
const ll INF = (ll)4e18;

void Ramez() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n + 1), radj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        radj[v].emplace_back(u, w);
    }

    int k;
    cin >> k;
    vector<int> imp(k);
    for (int i = 0; i < k; i++) {
        cin >> imp[i];
    }

    // dist_fwd[i][v] = distance from imp[i] to v
    // dist_rev[i][v] = distance from v to imp[i]
    vector<vector<ll>> dist_fwd(k, vector<ll>(n + 1, INF));
    vector<vector<ll>> dist_rev(k, vector<ll>(n + 1, INF));

    auto dijkstra = [&](int src, const vector<vector<pair<int, ll>>>& g, vector<ll>& dist) {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        dist[src] = 0;
        pq.emplace(0, src);
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& e : g[u]) {
                int v = e.first;
                ll w = e.second;
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
    };

    // Run Dijkstra from each important node
    for (int i = 0; i < k; i++) {
        dijkstra(imp[i], adj, dist_fwd[i]);
        dijkstra(imp[i], radj, dist_rev[i]);
    }

    // D[i][j] = dist from important i to j
    vector<vector<ll>> D(k, vector<ll>(k, INF));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            D[i][j] = dist_fwd[i][imp[j]];
        }
    }

    // bestPath[u][v]: min cost to start at imp[u], visit all imp, end at imp[v]
    vector<vector<ll>> bestPath(k, vector<ll>(k, INF));
    int FULL = (1 << k) - 1;

    // TSP-like DP for each starting important node
    for (int u = 0; u < k; u++) {
        vector<vector<ll>> dp(1 << k, vector<ll>(k, INF));
        dp[1 << u][u] = 0;
        for (int mask = 0; mask <= FULL; mask++) {
            for (int x = 0; x < k; x++) {
                if (!(mask & (1 << x))) continue;
                ll cur = dp[mask][x];
                if (cur >= INF) continue;
                for (int y = 0; y < k; y++) {
                    if (mask & (1 << y)) continue;
                    ll nd = cur + D[x][y];
                    int m2 = mask | (1 << y);
                    if (dp[m2][y] > nd) {
                        dp[m2][y] = nd;
                    }
                }
            }
        }
        for (int v = 0; v < k; v++) {
            bestPath[u][v] = dp[FULL][v];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int s, e;
        cin >> s >> e;
        ll ans = INF;
        for (int u = 0; u < k; u++) {
            ll ds = dist_rev[u][s];
            if (ds >= INF) continue;
            for (int v = 0; v < k; v++) {
                ll mid = bestPath[u][v];
                if (mid >= INF) continue;
                ll de = dist_fwd[v][e];
                if (de >= INF) continue;
                ans = min(ans, ds + mid + de);
            }
        }
        // If no valid path: output -1 (shouldn't happen in a strongly-connected graph)
        cout << (ans >= INF ? -1 : ans) << '\n';
    }
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}