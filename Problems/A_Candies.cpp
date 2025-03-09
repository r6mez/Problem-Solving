/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// A - Candies
// URL: https://vjudge.net/contest/698474#problem/A
// Time: 3/7/2025, 3:32:18 PM
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
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;

    vector<vi> dp(n + 1, vi(k + 1, -1));
    vector<vi> sdp(n + 1, vi(k + 1, -1));
    // dp[n][0] = 1;

    function<int(int, int)> calcSum;

    auto calcSol = [&](auto &&calcSol, int i, int rem) -> int {
        if(i == n) return rem == 0;
        if(dp[i][rem] != -1) return dp[i][rem];

        int ways = (calcSum(i + 1, rem) - calcSum(i + 1, rem - min(a[i], rem) - 1) + MOD) % MOD;
        return dp[i][rem] = ways;
    };

    calcSum = [&](int i, int rem) -> int {
        if(rem < 0) return 0;
        if (sdp[i][rem] != -1) return sdp[i][rem];
        return sdp[i][rem] = (calcSol(calcSol, i, rem)%MOD + calcSum(i, rem - 1)%MOD)%MOD;
    };

    cout << calcSol(calcSol, 0LL, k) << '\n';
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}