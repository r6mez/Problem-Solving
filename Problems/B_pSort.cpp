/*
    One day, I'm gonna grow wings
*/
// B. pSort
// URL: https://codeforces.com/contest/28/problem/B
// Time: 9/11/2025, 9:17:13 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
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

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    vi b(n); cin >> b;

    DSU d(n);
    for (int i = 0; i < n; i++){
        if(i + b[i] < n) d.merge(i, i + b[i]);
        if(i - b[i] >= 0) d.merge(i, i - b[i]);
    }
    
    for (int i = 0; i < n; i++){
        if(!d.same(i, a[i] - 1)) finish("NO");
    }
    
    finish("YES");
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}