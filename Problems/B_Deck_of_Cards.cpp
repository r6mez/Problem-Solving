/*
    One day, I'm gonna grow wings
*/
// B. Deck of Cards
// URL: https://codeforces.com/contest/2145/problem/B
// Time: 10/6/2025, 5:44:14 PM
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
    string s; cin >> s;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (char c : s) {
        if (c == '0') cnt0++;
        else if (c == '1') cnt1++;
        else cnt2++;
    }
    
    if (k == n) finish(string(n, '-'));

    string ans(n, '-');
    int l1 = cnt0, r1 = n - cnt1 - 1;
    if (l1 <= r1) for (int i = l1; i <= r1; ++i) ans[i] = '?';
    
    int l2 = cnt0 + cnt2, r2 = n - cnt1 - cnt2 - 1;
    if (l2 <= r2) for (int i = l2; i <= r2; ++i) ans[i] = '+';
    
    cout << ans << "\n";
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