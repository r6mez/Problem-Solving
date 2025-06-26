/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Road Construction
// URL: https://cses.fi/problemset/task/1676
// Time: 6/22/2025, 3:18:33 PM
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
    vector<int> parent, rank, size;
    int c, maxSize;

    DSU(int n) : parent(n + 1), rank(n + 1, 0), size(n + 1, 1), c(n), maxSize(1) {
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }

    int find(int i) {
        return (parent[i] == i ? i : (parent[i] = find(parent[i])));
    }

    bool same(int i, int j) {
        return find(i) == find(j);
    }

    int get_size(int i) {
        return size[find(i)];
    }

    // number of connected components
    int count() {
        return c;
    }

    int getMaxSize(){
        return maxSize;
    }

    int merge(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return -1;
        else --c;

        if (rank[i] > rank[j]) swap(i, j);
        parent[i] = j;
        size[j] += size[i];
        if (rank[i] == rank[j]) rank[j]++;

        if (size[j] > maxSize) {
            maxSize = size[j];
        }

        return j;
    }
};

void Ramez() {
    int n, m; cin >> n >> m;

    DSU dsu(n);

    while (m--) {
        int u, v; cin >> u >> v;
        dsu.merge(u, v);
        cout << dsu.count() << " " << dsu.getMaxSize() << "\n";
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