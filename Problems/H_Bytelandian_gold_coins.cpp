/*
    One day, I'm gonna grow wings
*/
// H - Bytelandian gold coins
// URL: https://vjudge.net/contest/694272#problem/H
// Time: 9/13/2025, 4:08:39 PM
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

unordered_map<int, int> dp;

int calc(int n){
    if(n == 0) return 0;
    if(dp.find(n) != dp.end()) return dp[n];
    return dp[n] = max(n, calc(n / 2) + calc(n / 3) + calc(n / 4));
}

void solve() {
    int n; while(cin >> n) cout << calc(n) << "\n";
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