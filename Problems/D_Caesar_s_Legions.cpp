/*
    One day, I'm gonna grow wings
*/
// D. Caesar's Legions
// URL: https://codeforces.com/problemset/problem/118/D
// Time: 10/30/2025, 1:16:51 PM
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
const int MOD = 100000000, INF = 2e18;

int n1, n2, k1, k2;

int dp[101][101][11][11];

int count(int cnt1, int cnt2, int prev1, int prev2){
    if(cnt1 > n1 || cnt2 > n2 || prev1 > k1 || prev2 > k2) return 0;
    
    auto &ret = dp[cnt1][cnt2][prev1][prev2];
    
    if(ret != -1) return ret;

    if(cnt1 == n1 && cnt2 == n2){
        return ret = 1;
    }

    return ret = (count(cnt1 + 1, cnt2, prev1 + 1, 0) + count(cnt1, cnt2 + 1, 0, prev2 + 1)) % MOD;
}


void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n1 >> n2 >> k1 >> k2;
    cout << count(0, 0, 0, 0) % MOD << "\n";
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