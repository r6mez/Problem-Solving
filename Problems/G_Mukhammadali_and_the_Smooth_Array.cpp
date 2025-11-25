/*
    One day, I'm gonna grow wings
*/
// G. Mukhammadali and the Smooth Array
// URL: https://codeforces.com/contest/2167/problem/G
// Time: 10/28/2025, 7:31:11 PM
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
    int n; cin >> n;
    vi a(n), c(n), dp(n);
    cin >> a >> c;
    
    int sum = accumulate(all(c), 0LL), worst = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = c[i];
        for (int j = 0; j < i; j++){
            if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + c[i]);
        }
        worst = max(worst, dp[i]);
    }

    int answer = sum - worst;
    cout << answer << '\n';
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