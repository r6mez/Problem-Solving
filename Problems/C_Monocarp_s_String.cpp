/*
    One day, I'm gonna grow wings
*/
// C. Monocarp's String
// URL: https://codeforces.com/contest/2145/problem/C
// Time: 10/6/2025, 6:27:02 PM
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
    int n; string s; cin >> n >> s;
    
    vi pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + (s[i - 1] == 'a' ? 1 : -1);
    
    int total = pref[n];
    if (total == 0) finish(0);

    vector<pii> p;
    
    for (int i = 0;i <= n;i++) p.emplace_back(pref[i], i);

    sort(all(p));

    int best = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        int need = pref[i] - total;
        auto l = lower_bound(p.begin(), p.end(), make_pair(need, (int)-1));
        auto it = upper_bound(p.begin(), p.end(), make_pair(need, (int)(i - 1)));
        if (it == p.begin()) continue;
        --it;
        if (it->first != need) continue;
        int j = it->second;
        if(i - j < n) best = min(best, i - j);
    }
    
    if (best == LLONG_MAX) finish(-1);
    cout << best << "\n";
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