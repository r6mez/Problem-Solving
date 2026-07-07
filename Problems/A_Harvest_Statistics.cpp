// A. Harvest Statistics
// URL: https://codeforces.com/group/zZYq310uLQ/contest/701118/problem/A
// Time: 7/6/2026, 4:41:17 PM
#include <algorithm>
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
    int n, q; cin >> n >> q;
    vi a(n + 1);
    vector<pii> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = {a[i], i};
    }

    sort(all(pref));

    for (int i = 1; i <= n; i++) {
        pref[i].first += pref[i - 1].first;
    }

    vector<pii> diff;
    for (int i = 1; i <= n; i++) {
        int o = (pref[n].first - pref[i].first) - (a[pref[i].second] * (n - i));
        diff.push_back({o, pref[i].second});
    }

    sort(all(diff));

    vi pmax(n);
    for (int i = 0; i < n; i++)
        pmax[i] = max(i ? pmax[i - 1] : 0LL, diff[i].second);

    while (q--) {
        int k; cin >> k;
        int idx = upper_bound(all(diff), make_pair(k, INF)) - diff.begin() - 1;
        cout << pmax[idx] << "\n";
    }
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