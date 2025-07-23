/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// G. MinOr Tree
// URL: https://codeforces.com/contest/1624/problem/G
// Time: 7/7/2025, 2:43:43 PM
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

struct Edge {
    int u, v, w;
    Edge() : u(0), v(0), w(0) {} 
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(Edge const &other) const { return w < other.w; }
};

inline istream& operator>>(istream& is, Edge &edge) {
    return (is >> edge.u >> edge.v >> edge.w);
}

// it returens the minimum cost of forming a minimum spanning tree
// if it can't be formed it returns -1
int kruskalMST(vector<Edge> &edges, int n){
    int cost = 0;
    DSU dsu(n + 1);
    sort(all(edges));
    for(const auto &[u, v, w] : edges){
        if(!dsu.same(u, v)){
            cost |= w;
            dsu.merge(u, v);
        }
    }
    int root = dsu.find(1);
    int sz = dsu.getSize(root);
    if(sz == n) return cost;
    else return -1;
}

void Ramez() {
    int n, m; cin >> n >> m;
    vector<Edge> edges(m); cin >> edges;
    for (int bit = 30; bit >= 0; bit--){
        vector<Edge> curr;
        for(auto [u, v, w] : edges){
            if(w & (1LL << bit)) continue;
            curr.emplace_back(u, v, w);
        }
        if(kruskalMST(curr, n) != -1) edges = curr;
    }

    int answer = kruskalMST(edges, n);
    cout << answer << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}