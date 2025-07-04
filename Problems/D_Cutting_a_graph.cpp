/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Cutting a graph
// URL: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D
// Time: 6/27/2025, 8:08:07 PM
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

    int find(int i) { return (parent[i] == i ? i : find(parent[i])); }

    bool same(int i, int j) { return find(i) == find(j); }

    int getSize(int i) { return size[find(i)]; }

    void cut(int i, int j){
                

    }

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
    int n, m, k; cin >> n >> m >> k;
    DSU dsu(n);
    while(m--){
        int u, v; cin >> u >> v;
        dsu.merge(u, v);
    }

    while (k--) {
        int u, v;
        string s; cin >> s >> u >> v;
        if (s == "cut") {
            dsu.cut(u, v);
        }

        if (s == "ask") {
            cout << (dsu.same(u, v) ? "YES" : "NO") << "\n";
        }
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