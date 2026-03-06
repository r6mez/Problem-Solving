// F. Mooclear Reactor 2
// URL: https://codeforces.com/contest/2200/problem/F
// Time: 3/6/2026, 10:24:05 AM
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

void solve() {
    int n, q;
    cin >> n >> q;
    vector<array<int, 2>> a(n); // y, x
    for (auto &i : a) cin >> i[1] >> i[0];

    // solve
    sort(a.rbegin(), a.rend());

    int ptr = 0, mx = 0, cur = 0;
    multiset<int> s;
    vi pref(n+1);
    
    for (int k = n; k >= 0; k--) {
        while (ptr < n && a[ptr][0] >= k) {
            cur += a[ptr][1];
            s.insert(a[ptr][1]);
            ptr++;
        }

        while (s.size() > k + 1) {
            cur -= *s.begin();
            s.erase(s.begin());
        }

        mx = max(mx, cur);

        pref[k] = (s.size() <= k) ? cur : cur - *s.begin();
    }

    for (int k = 1; k <= n; k++) {
        pref[k] = max(pref[k], pref[k - 1]);
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << max(mx, pref[y] + x) << ' ';
    }
    cout << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}