/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Roads not only in Berland
// URL: https://codeforces.com/contest/25/problem/D
// Time: 6/22/2025, 5:14:41 PM
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
    int n; cin >> n;
    DSU dsu(n);
    vector<pii> closedRoads;

    for (int k = 0; k < n - 1; ++k) {
        int u, v; cin >> u >> v;

        if (dsu.find(u) == dsu.find(v)) 
            closedRoads.push_back({ u, v });
        else dsu.merge(u, v);
    }

    vi roots;
    for (int i = 1; i <= n; ++i) {
        if (dsu.parent[i] == i) {
            roots.push_back(i);
        }
    }

    cout << closedRoads.size() << "\n";
    for (int i = 0; i < closedRoads.size(); ++i) {
        cout << closedRoads[i].first << " " << closedRoads[i].second << " "
            << roots[0] << " " << roots[i + 1] << "\n";
    }

}

/*
NOTES:
10
5 9
8 5
7 6
7 9
3 9
2 1
7 2
3 6
7 1
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}