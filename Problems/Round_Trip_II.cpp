/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Round Trip II
// URL: https://cses.fi/problemset/task/1678
// Time: 4/24/2025, 10:50:01 AM
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

// BFS
void Ramez() {
    int n, m; cin >> n >> m;
    vector<vi> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    // Color: 0 = unvisited, 1 = in‐stack, 2 = done
    vi color(n + 1, 0), parents(n + 1, -1);
    int start = -1, end = -1;;
    bool found = false;

    function<bool(int)> dfs = [&](int u) -> bool {
        color[u] = 1;

        for (int v : adj[u]) {
            if (color[v] == 0) {
                parents[v] = u;
                if (dfs(v)) return true;
            }

            if (color[v] == 1) {
                start = v;
                end = u;
                found = true;
                return true;
            }
        }

        color[u] = 2;
        return false;
    };

    for (int i = 1; i <= n && !found; i++) {
        if (color[i] == 0) dfs(i);
    }

    if (!found) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vi cycle;

    cycle.push_back(start);
    for (int x = end; x != start; x = parents[x]) cycle.push_back(x);
    cycle.push_back(start);
    reverse(all(cycle));

    cout << cycle.size() << "\n" << cycle;
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