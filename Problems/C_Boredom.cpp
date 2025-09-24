/*
    One day, I'm gonna grow wings
*/
// C. Boredom
// URL: https://codeforces.com/problemset/problem/456/C
// Time: 9/16/2025, 7:31:51 PM
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
const int MOD = 1000000007, INF = 2e18, N = 1e5 + 1;

int n; 
vi a;
int cnt[N];
int dp[N];

int calc(int x) {
    if (x <= 0) return 0;

    if (dp[x] != -1) return dp[x];
    
    int leave = calc(x - 1);
    int take = calc(x - 2) + cnt[x] * x;
    return dp[x] = max(take, leave);
}

void solve() {
    memset(dp, -1, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    a.resize(n);
    cin >> a;
    int mx = 0;
    for (int x : a) {
        cnt[x]++;
        mx = max(mx, x);
    }
    cout << calc(mx) << "\n";
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