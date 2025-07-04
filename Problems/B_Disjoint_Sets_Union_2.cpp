/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Disjoint Sets Union 2
// URL: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
// Time: 6/27/2025, 6:53:35 PM
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
    vector<int> parent, mn, mx, size;
    int count; // of component

    DSU(int n) : parent(n + 1), mn(n + 1), mx(n + 1), size(n + 1, 1), count(n) { 
        iota(all(parent), 0);
        iota(all(mn), 0);
        iota(all(mx), 0);
    }

    int find(int i) { return (parent[i] == i ? i : (parent[i] = find(parent[i]))); }

    bool same(int i, int j) { return find(i) == find(j); }

    int getSize(int i) { return size[find(i)]; }
    int getMin(int i) { return mn[find(i)]; }
    int getMax(int i) { return mx[find(i)]; }

    int merge(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return -1;
        else --count;
        if (size[i] > size[j]) swap(i, j);
        parent[i] = j;
        mn[j] = min(mn[i], mn[j]);
        mx[j] = max(mx[i], mx[j]);
        size[j] += size[i];        
        return j;
    }
};

void Ramez() {
    int n, m; cin >> n >> m;
    DSU dsu(n);
    while(m--){
        int u, v;
        string s; cin >> s >> u;
        if(s == "union"){
            cin >> v;
            dsu.merge(u, v);
        }

        if(s == "get"){
            cout << dsu.getMin(u) << " " << dsu.getMax(u) << " " << dsu.getSize(u) << "\n";
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