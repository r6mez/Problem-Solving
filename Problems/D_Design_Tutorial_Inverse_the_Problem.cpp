/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Design Tutorial: Inverse the Problem
// URL: https://codeforces.com/contest/472/problem/D
// Time: 7/7/2025, 4:20:28 PM
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

struct DSU {
    vector<int> parent, size;
    int count; // of component

    DSU(int n) : parent(n + 1), size(n + 1, 1), count(n) { iota(all(parent), 0); }

    int find(int i) { return (parent[i] == i ? i : (parent[i] = find(parent[i]))); }

    bool same(int i, int j) { return find(i) == find(j); }

    int getSize(int i) { return size[find(i)]; }

    int merge(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return -1;
        else --count;
        if (size[i] > size[j]) swap(i, j);
        parent[i] = j;
        size[j] += size[i];
        return j;
    }
};

class Edge {
public:
    int u, v, w;
    Edge() : u(0), v(0), w(0) {}
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(Edge const& other) const { return w < other.w; }
};

inline istream& operator>>(istream& is, Edge& edge) {
    return (is >> edge.u >> edge.v >> edge.w);
}


void Ramez() {
    int n; cin >> n;
    vector<vi> matrix(n, vi(n));
    for (auto& row : matrix) cin >> row;

    for (int i = 0; i < n; i++) {
        if (matrix[i][i] != 0) { cout << "NO\n"; return; }
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i] || matrix[i][j] <= 0) {
                cout << "NO\n";
                return;
            }
        }
    }

    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.emplace_back(i, j, matrix[i][j]);
        }
    }

    sort(all(edges));

    DSU dsu(n);
    vector<vector<pii>> tree(n);
    for (auto& [u, v, w] : edges) {
        if(dsu.same(u, v)) continue;
        if (dsu.merge(u, v)) {
            tree[u].push_back({ v, w });
            tree[v].push_back({ u, w });
        }
    }    

    vi distance(n);
    for (int src = 0; src < n; src++) {
        fill(all(distance), -1); distance[src] = 0;
        queue<int> q; q.push(src);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &[v, w] : tree[u]) {
                if (distance[v] == -1) {
                    distance[v] = distance[u] + w;
                    q.push(v);
                }
            }
        }

        for (int j = 0; j < n; j++) {
            if (distance[j] != matrix[src][j]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
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