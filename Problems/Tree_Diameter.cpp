/*
    I was alone in an empty universe.
    A universe too small and at the same time... too infinite.
*/
// Tree Diameter
// URL: https://cses.fi/problemset/task/1131
// Time: 8/7/2025, 4:37:48 PM
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

int32_t main() {
    FastIO();
    int n;
    cin >> n;
    vector<vi> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    auto bfs = [&](int src) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        int far = src;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    if (dist[v] > dist[far]) far = v;
                }
            }
        }
        return make_pair(far, dist[far]);
    };
    // First BFS from node 1 (or any node)
    int start = 1;
    auto res1 = bfs(start);
    // Second BFS from the farthest node found
    auto res2 = bfs(res1.first);
    // The second distance is the diameter
    cout << res2.second;
    return 0;
}
