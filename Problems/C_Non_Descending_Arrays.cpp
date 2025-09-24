/*
    One day, I'm gonna grow wings
*/
// C. Non-Descending Arrays
// URL: https://codeforces.com/contest/2144/problem/C
// Time: 9/15/2025, 5:59:40 PM
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
const int MOD = 998244353, INF = 2e18, N = 100;

int n;
vector<int> a, b;
int dp[N][2];

int calc(int i, int s) {
    if (i == 0) return dp[i][s] = 1;
    if (dp[i][s] != -1) return dp[i][s];

    dp[i][s] = 0;

    int ai = s == 0 ? a[i] : b[i];
    int bi = s == 0 ? b[i] : a[i];
    if (a[i - 1] <= ai && b[i - 1] <= bi) dp[i][s] = (dp[i][s] + calc(i - 1, 0)) % MOD;
    if (b[i - 1] <= ai && a[i - 1] <= bi) dp[i][s] = (dp[i][s] + calc(i - 1, 1)) % MOD;
    
    return dp[i][s];
}

void solve() {
    cin >> n;
    a.resize(n, 0); cin >> a;
    b.resize(n, 0); cin >> b;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            dp[i][j] = -1;
        }
    }

    int ans = (calc(n - 1, 0) + calc(n - 1, 1)) % MOD;
    cout << ans << '\n';
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