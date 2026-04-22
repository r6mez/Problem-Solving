// H. Help That Graph
// URL: https://codeforces.com/group/Rilx5irOux/contest/678837/problem/H
// Time: 4/18/2026, 1:54:05 AM
#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <functional>
#include <vector>
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
const int MOD = 1000000007, INF = 2e18;

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
    int n, m, q; cin >> n >> m >> q;
    vector<pii> edges;
    
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        edges.push_back({x, y});
    }

    sort(all(edges), [](pii a, pii b){
        return a.first + a.second > b.first + b.second;
    });

    vector<pii> seconds(q);
    for (int i = 0; i < q; i++) {
        int s; cin >> s;
        seconds[i] = {s, i};
    }

    sort(all(seconds), greater<>());

    DSU dsu(n);
    int p = 0;
    vi answer(q);
    for(int i = 0; i < m; i++){
        auto [u, v] = edges[i];
        int sum = u + v;
        int comp_count = dsu.count;
        dsu.merge(u, v);
        while(seconds[p].first >= sum && p < q) {
            answer[seconds[p].second] = comp_count;
            p++;
        }
    }

    while(p < q){
        answer[seconds[p].second] = dsu.count;
        p++;
    }

    cout << answer << "\n";
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