/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D1. Mocha and Diana (Easy Version)
// URL: https://codeforces.com/contest/1559/problem/D1
// Time: 6/23/2025, 3:16:09 PM
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


void Ramez() {
    int n, m1, m2; cin >> n >> m1 >> m2;

    DSU d1(n), d2(n);

    for (int i = 0; i < m1; i++) {
        int u, v; cin >> u >> v;
        d1.merge(u, v);
    }

    for (int i = 0; i < m2; i++) {
        int u, v; cin >> u >> v;
        d2.merge(u, v);
    }

    vector<pii> res;

    for (int i = 1; i <= n; ++i)
    {
        if (!d1.same(1, i) && !d2.same(1, i))
        {
            d1.merge(1, i);
            d2.merge(1, i);
            res.emplace_back(1, i);
        }
    }
    int i = 1, j = 1;
    while (i <= n && j <= n) {
        while (i <= n && d1.same(1, i)) ++i;
        while (j <= n && d2.same(1, j)) ++j;
        if (i <= n && j <= n && !d1.same(i, j) && !d2.same(i, j)) {
            d1.merge(i, j);
            d2.merge(i, j);
            res.emplace_back(i, j);
            ++i, ++j;
        }
    }

    cout << res.size() << '\n';
    for (auto& [u, v] : res) cout << u << " " << v << '\n';
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