/*
    One day, I'm gonna grow wings
*/
// B16 - Frog 1
// URL: https://atcoder.jp/contests/tessoku-book/tasks/dp_a?lang=en
// Time: 9/12/2025, 6:49:42 PM
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

// iterative
void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    int dp[n + 1]{0};

    for (int i = n - 2; i >= 0; i--) {
        int one = i <= n - 2 ? dp[i + 1] + abs(a[i + 1] - a[i]) : INF;
        int two = i <= n - 3 ? dp[i + 2] + abs(a[i + 2] - a[i]) : INF;
        dp[i] = min(one, two);
    }

    cout << dp[0];
}

// recursive 
// int n;   
// vi a;
// const int INF = 2e18, N = 1e5 + 1;
// int dp[N];

// int calc(int i){
//     if(i >= n) return INF;

//     if(i == n - 1) return 0;

//     if(dp[i] != -1) return dp[i];

//     int one = i <= n - 2? calc(i + 1) + abs(a[i + 1] - a[i]) : INF;
//     int two = i <= n - 3? calc(i + 2) + abs(a[i + 2] - a[i]) : INF;
//     return dp[i] = min(one, two);
// }

// void solve() {
//     memset(dp, -1, sizeof(dp));
//     cin >> n;
//     a.resize(n);
//     cin >> a;
//     cout << calc(0);
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