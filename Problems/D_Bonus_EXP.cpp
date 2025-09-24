/*
    One day, I'm gonna grow wings
*/
// D - Bonus EXP
// URL: https://atcoder.jp/contests/abc369/tasks/abc369_d?lang=en
// Time: 9/14/2025, 11:40:15 AM
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
const int MOD = 1000000007, INF = 2e18, N = 2e5 + 1;

//iteriative
void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    int dp[n + 1][2] = {0}; 
    
    for(int i = n - 1; i >= 0; i--){
        for (int parity = 0; parity < 2; parity++){
            int take = dp[i + 1][!parity] + a[i] + (parity % 2 == 0) * a[i];
            int leave = dp[i + 1][parity];
            dp[i][parity] = max(take, leave);
        }
    }

    cout << dp[0][1];
}

// recu
// int calc(int i, int parity) {
//     if (i == n) return 0;
//     if (dp[i][parity] != -1) return dp[i][parity];
//     int take = calc(i + 1, !parity) + a[i] + (parity % 2 == 0) * a[i];
//     int leave = calc(i + 1, parity);
//     return dp[i][parity] = max(take, leave);
// }

// void solve() {
//     memset(dp, -1, sizeof(dp));
//     cin >> n;
//     a.resize(n);
//     cin >> a;
//     cout << calc(0, 1);
// }

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}