/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// H. Don't Blame Me
// URL: https://codeforces.com/contest/1829/problem/H
// Time: 5/28/2025, 10:16:01 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void Ramez() {
    int n, x; cin >> n >> x;
    vi a(n + 1);
    vector<vi> dp(n + 1, vi(65, 0));

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];

        for (int mask = 0; mask < 64; ++mask) {
            dp[i][mask] = (dp[i][mask] + dp[i - 1][mask])%MOD; // don't use a[i]
            dp[i][mask & a[i]] = (dp[i][mask & a[i]] + dp[i - 1][mask])%MOD; // use a[i]
        }

        dp[i][a[i]] = (dp[i][a[i]] + 1) % MOD; // start new sequence
    }


    int ans = 0;
    for (int mask = 0; mask < 64; ++mask) {
        if (__builtin_popcount(mask) == x) {
            ans = (ans + dp[n][mask]) % MOD;
        }
    }

    cout << ans << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}