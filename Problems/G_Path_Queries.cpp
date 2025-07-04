/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// G. Path Queries
// URL: https://codeforces.com/contest/1213/problem/G
// Time: 6/29/2025, 2:40:26 PM
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
        int result = size[i] * size[j];
        parent[i] = j;
        size[j] += size[i];
        return result;
    }
};

void Ramez() {
    int n, m; cin >> n >> m;

    DSU dsu(n);

    vector<array<int, 3>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = { w, u, v };
    }

    sort(all(edges));

    vi prefix(n - 1), weights;
    int run = 0;
    for (int i = 0; i < n - 1; i++) {
        auto [w, u, v] = edges[i];
        run += dsu.merge(u, v);
        prefix[i] = run;
        weights.push_back(w);
    }

    while (m--) {
        int q; cin >> q;
        int idx = upper_bound(all(weights), q) - weights.begin() - 1;
        cout << (idx >= 0 ? prefix[idx] : 0) << " ";
    }
    cout << "\n";
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