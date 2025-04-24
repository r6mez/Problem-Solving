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
    vi color(n + 1, 0), parents(n + 1, -1), cycle;
    bool found = false;

    function<bool(int)> dfs = [&](int parent) -> bool {
        color[parent] = 1;
        for (int child : adj[parent]) {
            if (color[child] == 0) {
                parents[child] = parent;
                if (dfs(child)) return true;
            }
            else if (color[child] == 1) {
                // back‐edge u→v ⇒ found a cycle
                found = true;
                cycle.push_back(child);
                for (int x = parent; x != child; x = parents[x])
                    cycle.push_back(x);
                cycle.push_back(child);
                reverse(all(cycle));
                return true;
            }
        }
        color[parent] = 2;
        return false;
    };

    for (int i = 1; i <= n && !found; i++) {
        if (color[i] == 0) dfs(i);
    }

    if (!found) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << cycle.size() << "\n";
        cout << cycle << "\n";
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