/*
    One day, I'm gonna grow wings
*/
// E2. Escape The Maze (hard version)
// URL: https://codeforces.com/contest/1611/problem/E2
// Time: 8/23/2025, 1:01:34 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> auto& operator<<(auto& o, vector<T>& v) { for (auto& e : v) o << e << ' '; return o; }
template<typename T> auto& operator>>(auto& i, vector<T>& v) { for (auto& e : v) i >> e; return i; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void solve() {
    int n, k; cin >> n >> k;
    vector<vi> adj(n);
    vi  x(k), nearest(n, n);
    for (int& i : x) { cin >> i; i--; nearest[i] = 0; }
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    function<int(int, int, int)> cnt = [&](int u, int distance, int p) -> int {
        bool children = true;
        int sum = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            int c = cnt(v, distance + 1, u);
            if (c < 0) children = false;
            sum += c;

            nearest[u] = min(nearest[u], nearest[v] + 1);
        }

        if (nearest[u] <= distance) return 1;

        if (sum == 0 || children == false) return -1;

        return sum;
    };

    cout << cnt(0, 0, -1) << "\n";
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