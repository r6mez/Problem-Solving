/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. People are leaving
// URL: https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/A
// Time: 6/27/2025, 8:56:22 PM
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
    vector<int> parent, size, mx;
    int count; // of component

    DSU(int n) : parent(n + 1), mx(n + 1), size(n + 1, 1), count(n) { iota(all(parent), 0); iota(all(mx), 0); }

    int find(int i) { return (parent[i] == i ? i : (parent[i] = find(parent[i]))); }

    bool same(int i, int j) { return find(i) == find(j); }

    int getSize(int i) { return size[find(i)]; }
    int getMax(int i) { return mx[find(i)]; }

    int merge(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return -1;
        else --count;
        if (size[i] > size[j]) swap(i, j);
        parent[i] = j;
        size[j] += size[i];        
        mx[j] = max(mx[j], mx[i]);
        return j;
    }
};

void Ramez() {
    int n, m; cin >> n >> m;
    DSU dsu(n + 2);
    
    while(m--){
        char c; int x; cin >> c >> x;
        if(c == '-') dsu.merge(x, x + 1);
        else cout << (dsu.getMax(x) == n + 1? -1 : dsu.getMax(x)) << "\n";
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