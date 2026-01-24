// D1. Tree Coloring (Easy Version)
// URL: https://codeforces.com/contest/2183/problem/D1
// Time: 1/22/2026, 9:44:28 PM
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
    vector<vi> adj(n + 1);
    vi degree(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    vi parent(n + 1, 0);
    vi depth(n + 1, 0);
    int maxDepth = 0;

    function<void(int, int)> dfs = [&](int u, int p) {
        parent[u] = p;
        for (auto& v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            maxDepth = max(maxDepth, depth[v]);
            dfs(v, u);
        }
    };
    
    dfs(1, 0);

    vector<vi> nodesByDist(maxDepth + 1);
    for (int i = 1; i <= n; i++) {
        nodesByDist[depth[i]].push_back(i);
    }

    // We want to pick leaves nodes first to avoid blocking big subtrees
    for (auto& layer : nodesByDist) {
        sort(layer.begin(), layer.end(), [&](int a, int b) {
            return degree[a] < degree[b];
        });
    }

    auto run = [&](bool skipRoot) -> int {
        int ops = 0;
        int remaining = n;

        vector<deque<int>> active_layers(maxDepth + 1);
        for (int d = 0; d <= maxDepth; ++d) {
            for (int u : nodesByDist[d]) active_layers[d].push_back(u);
        }

        while (remaining) {
            ops++;
            map<int, bool> blocked_parents;

            for (int d = 0; d <= maxDepth; d++) {
                if (active_layers[d].empty()) continue;

                if (skipRoot && ops == 1 && d == 0) continue;

                int picked_node = -1;
                int sz = active_layers[d].size();
                for (int k = 0; k < sz; ++k) {
                    int u = active_layers[d].front();
                    active_layers[d].pop_front();

                    bool parent_conflict = false;
                    if (d > 0 && blocked_parents.count(parent[u])) {
                        parent_conflict = true;
                    }

                    if (!parent_conflict) {
                        picked_node = u;
                        remaining--;
                        blocked_parents[u] = true;
                        break;
                    }
                    else {
                        active_layers[d].push_back(u);
                    }
                }
            }
        }

        return ops;
    };

    int ans1 = run(false); // Standard greedy
    int ans2 = run(true);  // Skip root in op 1

    cout << min(ans1, ans2) << "\n";
}

/*
we have a tree rooted at 1
each op we color a set of nodes black
nodes in the set should :
- has no common edge
- have different distances from the root
what's the minimum number of ops to color all nodes black?

n <= 2e5

if we classify nodes by their distance from root
1, 2, 3, 4, 5, 6

in each op
we can can loop over distances, picking on node from each distance
but with condition that it's parent wasn't picked in this op
worst case: idk, let's try
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}