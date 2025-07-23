/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Canals of Beersheba
// URL: https://codeforces.com/gym/537640/problem/C
// Time: 7/21/2025, 6:30:33 PM
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

struct Tree {
    int n, LOG;
    vi depth;
    vi subtreeSize;
    vector<vi> up;

    Tree(const vector<vi>& adj, int root = 0) {
        n = adj.size();
        LOG = ceil(log2(n));
        depth.assign(n, 0);
        subtreeSize.assign(n, 0);
        up.assign(LOG + 1, vi(n, -1));

        dfs(adj, root, root);

        for (int k = 1; k <= LOG; ++k) {
            for (int v = 0; v < n; ++v) {
                int p = up[k - 1][v];
                up[k][v] = (p < 0 ? -1 : up[k - 1][p]);
            }
        }
    }

    void dfs(const vector<vi>& adj, int v, int parent) {
        up[0][v] = parent;
        subtreeSize[v] = 1;
        for (int u : adj[v]) {
            if (u == parent) continue;
            depth[u] = depth[v] + 1;
            dfs(adj, u, v);
            subtreeSize[v] += subtreeSize[u];
        }
    }

    int kth_ancestor(int v, int dist) const {
        for (int k = 0; dist && v >= 0; ++k) {
            if (dist & 1) v = up[k][v];
            dist >>= 1;
        }
        return v;
    }

    int LCA(int a, int b) const {
        if (depth[a] < depth[b]) swap(a, b);
        a = kth_ancestor(a, depth[a] - depth[b]);
        if (a == b) return a;
        for (int k = LOG; k >= 0; --k) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }
        return up[0][a];
    }
};

void Ramez() {
    int n;
    cin >> n;
    vector<vi> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Tree tree(adj, 0);

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        int lcaNode = tree.LCA(a, b);
        int dist = tree.depth[a] + tree.depth[b] - 2 * tree.depth[lcaNode];

        if (dist % 2 == 0) {
            int k = dist / 2;
            int meetingNode;
            
            if (tree.depth[a] > tree.depth[b]) meetingNode = tree.kth_ancestor(a, k);
            else meetingNode = tree.kth_ancestor(b, k);
            
            int nodeA = tree.kth_ancestor(a, k - 1);
            int nodeB = tree.kth_ancestor(b, k - 1);

            int aliceScore, bobScore;

            if (tree.up[0][nodeA] == meetingNode) aliceScore = tree.subtreeSize[nodeA];
            else aliceScore = n - tree.subtreeSize[meetingNode];
            

            
            if (tree.up[0][nodeB] == meetingNode) bobScore = tree.subtreeSize[nodeB];
            else bobScore = n - tree.subtreeSize[meetingNode];
            
            if (aliceScore > bobScore) cout << "Alice\n";
            else if (bobScore > aliceScore) cout << "Bob\n";
            else cout << "Draw\n";
        }
        else {
            int k = (dist - 1) / 2;
            int path_a_to_lca = tree.depth[a] - tree.depth[lcaNode];

            int aliceScore, bobScore;
            if (k < path_a_to_lca) {
                int u = tree.kth_ancestor(a, k);
                aliceScore = tree.subtreeSize[u];
                bobScore = n - aliceScore;
            }
            else {
                int v = tree.kth_ancestor(b, k);
                bobScore = tree.subtreeSize[v];
                aliceScore = n - bobScore;
            }

            if (aliceScore > bobScore) cout << "Alice\n";
            else if (bobScore > aliceScore) cout << "Bob\n";
            else cout << "Draw\n";
        }
    }
}

/*
NOTES:
1. Preprocessing: Use DFS to find depths, parents (for LCA), and subtree sizes for all nodes. Build a binary lifting table for fast LCA and k-th ancestor queries.
2. Even Distance: Players meet at a single node. They are trapped in the components from which they approached. The scores are the sizes of the subtrees rooted at the nodes they occupied just before meeting.
3. Odd Distance: Players cross over an edge. The tree is partitioned into two territories. The scores are the sizes of these two territories. We determine which side of the LCA the split happens to correctly calculate the partition sizes.
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}