// K. Selling The Contribution
// URL: https://codeforces.com/group/Rilx5irOux/contest/636158/problem/K
// Time: 5/8/2026, 9:09:19 PM
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
    int n, k; cin >> n >> k;
    vector<pii> p(n);
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        p[i].first = i;
        cin >> p[i].second;
    }

    sort(all(p), [&](pii x, pii y) {
        return (x.second - a[x.first]) > (y.second - a[y.first]);
    });

    for (int i = 0; i < k; i++) {
        a[p[i].first] = p[i].second;
    }
    
    cout << a << "\n";
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