/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Hongcow Builds A Nation
// URL: https://codeforces.com/problemset/problem/744/A
// Time: 7/8/2025, 8:09:36 PM
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
    int u, v;
    Edge() : u(0), v(0) {}
    Edge(int u, int v) : u(u), v(v) {}
};

inline istream& operator>>(istream& is, Edge& edge) {
    return (is >> edge.u >> edge.v);
}

void Ramez() {
    int n, m, k; cin >> n >> m >> k;
    vi gov(k); cin >> gov;
    sort(all(gov));

    DSU dsu(n);
    vector<bool> isGov(n + 1, false);
    for (int govNode : gov) {
        isGov[govNode] = true;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.merge(u, v);
    }

    for (int i = 1; i <= n; i++) {
        if (isGov[i]) {
            isGov[dsu.find(i)] = true;
        }
    }

    vector<int> govSizes;
    int totalNormalNodes = 0;

    set<int> leaders;
    for (int i = 1; i <= n; i++) {
        leaders.insert(dsu.find(i));
    }

    for (int leader : leaders) {
        if (isGov[leader]) govSizes.push_back(dsu.getSize(leader));
        else totalNormalNodes += dsu.getSize(leader);
        
    }

    sort(all(govSizes), greater<int>());

    if (!govSizes.empty()) {
        govSizes[0] += totalNormalNodes;
    }

    int maximumEdges = 0;
    for (int size : govSizes) {
        maximumEdges += size * (size - 1) / 2;
    }

    cout << maximumEdges - m << "\n";
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