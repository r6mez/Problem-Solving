/*
    One day, I'm gonna grow wings
*/
// E. Sleeping Schedule
// URL: https://codeforces.com/problemset/problem/1324/E
// Time: 9/13/2025, 4:30:21 PM
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

int n, h, l, r; 
vi a;

const int H = 2001, N = 2001;
int dp[N][H];
int calc(int i, int currH){
    if(i == n) return 0;
    if(dp[i][currH] != -1) return dp[i][currH];

    int nxt1 = (currH + a[i]) % h;
    int nxt2 = (currH + a[i] - 1 + h) % h;
    return dp[i][currH] = max(calc(i+1, nxt1) + (l <= nxt1 && nxt1 <= r),
               calc(i+1, nxt2) + (l <= nxt2 && nxt2 <= r));
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> h >> l >> r;
    a.resize(n);
    cin >> a;
    cout << calc(0, 0);
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