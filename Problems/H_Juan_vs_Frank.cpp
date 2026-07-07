// H. Juan vs Frank
// URL: https://codeforces.com/group/zZYq310uLQ/contest/701118/problem/H
// Time: 7/5/2026, 1:20:15 AM
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
const int MOD = 1000000007, inf = 2e18;

struct FenwickPURQ {    
    int n;
    vi f;

    FenwickPURQ(int size) : n(size), f(n + 1, 0) {}

    void upd(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) f[idx] ^= val;
    }
    
    int query(int idx) { // 1 .. idx
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res ^= f[idx];
        return res;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    FenwickPURQ fw(n);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        fw.upd(i, x);
    }

    while(q--){
        char op; cin >> op;
        if(op == 'P'){
            int l, r; cin >> l >> r;
            int res = fw.query(r) ^ fw.query(l - 1);
            if(res == 0) cout << "JUAN\n";
            else cout << "FRANK\n";
        } else {
            int k, x; cin >> k >> x;
            int old = fw.query(k) ^ fw.query(k - 1);
            fw.upd(k, old);
            fw.upd(k, old + x);
        }
    }
}

/*

*/

signed main() {
  // UseFile();
  FastIO();
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}