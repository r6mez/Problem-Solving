// H. Sum in Range
// URL: https://codeforces.com/group/Rilx5irOux/contest/638270/problem/H
// Time: 5/13/2026, 2:47:26 PM
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
const int MOD = 1000000007, INF = 2e18;

struct FenwickPURQ {    
    int n;
    vi f;

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) f[idx] += val;
    }
    
    int prefix(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res += f[idx];
        return res;
    }
    
    FenwickPURQ(int size) : n(size), f(n + 1, 0) {}

    int rangeQuery(int l, int r) {
        return prefix(r) - prefix(l - 1);
    }
};

struct query{
    int l, r, k, answer, idx;
};

void solve() {
    int n; cin >> n; 
    vector<pii> ta(n + 1); 
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        ta[i] = {x, i};
    }

    
    sort(all(ta));

    vector<query> qs;

    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int l, r, k; cin >> l >> r >> k;
        qs.push_back({l, r,k, 0, i});
    }

    sort(all(qs), [](query &x, query &y){
        return x.k < y.k;
    });

    int p = 1;
    FenwickPURQ fn(n + 1);
    for(int i = 0; i < q; i++){
        auto &[l, r, k, answer, idx] = qs[i];
        while(p <= n && ta[p].first <= k){
            fn.add(ta[p].second, ta[p].first);
            p++;
        }

        answer = fn.rangeQuery(l, r);
    }

    sort(all(qs), [](query x, query y){
        return x.idx < y.idx;
    });

    for(int i = 0; i < q; i++){
        auto &[l, r, k, answer, idx] = qs[i];
        cout << answer << "\n";
    }
}

/*

*/

signed main() {
    // UseFile();
    // FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}