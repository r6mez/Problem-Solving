/*
    I was alone in an empty universe.
    A universe too small and at the same time... too infinite.
*/
// C. Double Perspective
// URL: https://codeforces.com/contest/2130/problem/C
// Time: 7/31/2025, 6:43:52 PM
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
    int u, v, idx;
    Edge() : u(0), v(0), idx(0) {} 
    Edge(int u, int v, int idx) : u(u), v(v), idx(idx) {}
    bool operator<(Edge const &other) const { return v - u > other.v - other.u; }
};

void Ramez() {
    int n; cin >> n;
    vector<Edge> es(n); 
    for (int i = 0; i < n; i++){
        cin >> es[i].u >> es[i].v; es[i].idx = i + 1;
    }
    sort(all(es));
    
    DSU dsu(1e5);
    
    vi selected;
    for (int i = 0; i < n; i++){
        auto [u, v, idx] = es[i];
        if(!dsu.same(u, v)){
            selected.push_back(idx);
            dsu.merge(u, v);
        }
    }
    cout << selected.size() << '\n';
    cout << selected << "\n";
}

/*

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}