/*
    One day, I'm gonna grow wings
*/
// D. Sliding Tree
// URL: https://codeforces.com/contest/2134/problem/D
// Time: 8/26/2025, 7:17:03 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

pair<int, vector<int>> getFar(int src, const vector<vector<int>>& adj) {
    int n = (int)adj.size() - 1;
    vector<int> dist(n + 1, -1), parent(n + 1, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    int far = src;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist[u] > dist[far]) far = u;
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return { far, parent };
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int node = -1;
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() >= 3) {
            node = i;
            break;
        }
    }

    if (node == -1) {
        cout << -1 << '\n';
        return;
    }

    auto r1 = getFar(node, adj);
    int u = r1.first;
    auto r2 = getFar(u, adj);
    int v = r2.first;
    vector<int> parent = r2.second;

    vector<int> diam;
    int cur = v;
    while (cur != -1) {
        diam.push_back(cur);
        if (cur == u) break;
        cur = parent[cur];
    }
    reverse(all(diam));

    int b = -1, a = -1, c = -1;
    unordered_set<int> onDiam(diam.begin(), diam.end());
    for (int i = 1; i < diam.size() - 1; ++i) {
        int nodeOnDiam = diam[i];
        if (adj[nodeOnDiam].size() >= 3) {
            a = diam[i - 1];
            b = nodeOnDiam;

            for (int neigh : adj[b]) {
                if (neigh != a && onDiam.count(neigh) == 0) {
                    c = neigh;
                    break;
                }
            }
        }
    }

    cout << a << ' ' << b << ' ' << c << '\n';
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