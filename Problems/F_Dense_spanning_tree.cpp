/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// F. Dense spanning tree
// URL: https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/F
// Time: 7/7/2025, 3:27:48 PM
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

// it returns the minimum cost of forming a minimum spanning tree
// if it can't be formed it returns -1
int kruskalMST(vector<Edge>& edges, int n, int l, int r) {
    int cost = 0;
    DSU dsu(n + 1);
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = l; i <= r; i++){
        auto& [u, v, w] = edges[i];
        if (!dsu.same(u, v)) {
            mn = min(mn, w);
            mx = max(mx, w);
            dsu.merge(u, v);
        }
    }
    int root = dsu.find(1);
    int sz = dsu.getSize(root);
    if (sz == n) return mx - mn;
    else return INT_MAX;
}


void Ramez() {
    int n, m; cin >> n >> m;
    vector<Edge> edges(m); cin >> edges;
    sort(all(edges));
    
    int answer = INT_MAX;
    int r = 0;
    for (int l = 0; l < m; l++) {
        if (r < l) r = l;
        while (r < m && kruskalMST(edges, n, l, r) == INT_MAX) {
            r++;
        }
        if (r < m) {
            answer = min(answer, kruskalMST(edges, n, l, r));
        }
    }
    if(answer == INT_MAX) cout << "NO\n";
    else cout << "YES\n" << answer << "\n";
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