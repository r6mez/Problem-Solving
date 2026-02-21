// E. Round Dance
// URL: https://codeforces.com/problemset/problem/1833/E
// Time: 2/6/2026, 6:27:42 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

void solve() {
    int n; cin >> n;
    vi neighbor(n); for (int& i : neighbor) cin >> i, i--;

    vector<set<int>> adj(n);
    for (int u = 0; u < n; u++) {
        int v = neighbor[u];
        adj[u].insert(v);
        adj[v].insert(u);
    }

    int components = 0, cycles = 0;
    vi vis(n + 1, 0);


    function<bool(int, int)> dfs = [&](int u, int p) -> bool {
        if (vis[u]) return true;
        
        vis[u] = true;

        for (int v : adj[u]) {
            if (v == p) continue;
            if (dfs(v, u)) return true;
        }

        return false;
    };

    for (int u = 0; u < n; u++) {
        if (vis[u] == true) continue;
        if (dfs(u, -1)) cycles++;
        components++;
    }

    int lines = components - cycles;
    int min_circles = cycles + (lines > 0);
    int max_circles = components;

    cout << min_circles << ' ' << max_circles << "\n";
}

/*
each person has two neighbors
we know one of them, the other could be anyone

what's the minimum number of circles we can generate
and what's the maximum?

I think if we know the number of componenets

+-+-+  +-+  +-+-+-+
       +-+

if one of them is a cycle, we can't join it with another one
minimim is connecting lines = 1 + cycles, maximum is the number of components
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}