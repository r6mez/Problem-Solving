/*
    One day, I'm gonna grow wings
*/
// E. Block Sequence
// URL: https://codeforces.com/problemset/problem/1881/E
// Time: 9/12/2025, 6:13:20 PM
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
const int MOD = 1000000007;

// iterative
void solve(){
    int n; cin >> n;
    vi a(n); cin >> a;
    
    int dp[n + 1]{0};
    for (int i = n - 1; i >= 0; i--){
        if(i + a[i] >= n) {
            dp[i] = dp[i + 1] + 1;
            continue;
        }

        dp[i] = min(dp[i + a[i] + 1], dp[i + 1] + 1);
    }
    
    cout << dp[0] << "\n";
}


// recursive
// int n;
// vi a;
// const int N = 2e5 + 1;
// int dp[N];

// int cnt(int i){
//     if(i >= n) return 0;
    
//     if(dp[i] != -1) return dp[i];

//     if(i + a[i] >= n) return dp[i] = cnt(i + 1) + 1; // no other choice
//     int take = cnt(i + a[i] + 1);
//     int leave = cnt(i + 1) + 1;

//     return dp[i] = min(take, leave);
// }

// void solve() {
//     memset(dp, -1, sizeof(dp));
//     cin >> n;
//     a.resize(n);
//     cin >> a;
    
//     cout << cnt(0) << "\n";
// }

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}