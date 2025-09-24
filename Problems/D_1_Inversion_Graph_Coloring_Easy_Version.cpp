/*
    One day, I'm gonna grow wings
*/
// D1. Inversion Graph Coloring (Easy Version)
// URL: https://codeforces.com/contest/2143/problem/D1
// Time: 9/17/2025, 6:18:02 PM
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

int n;
vi a;

int dp[301][301][301];

int calc(int i, int last, int last2) {
    if (i == n) return 1;

    int& ret = dp[i][last][last2];
    if (ret != -1) return ret;

    int res = calc(i + 1, last, last2);
    int x = a[i];
    
    if (last <= x) res = (res + calc(i + 1, x, last2)) % MOD;
    else if (last2 <= x) res = (res + calc(i + 1, last, x)) % MOD;

    return ret = res;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    a.resize(n);
    for (int i = 0;i < n;i++) cin >> a[i];

    cout << calc(0, 0, 0) % MOD << "\n";
}


/*
the sequence can only contain one down pair
bi > bj

if it contains bi > bj > bk -> invalid

so we can dp with a take or leave pattern
but only take when there's no two element in the sequence bigger that a[i];
I think sience n = 300, brute forcing is okay, we also may use a set
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}