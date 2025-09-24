/*
    One day, I'm gonna grow wings
*/
// C. Mortal Kombat Tower
// URL: https://codeforces.com/problemset/problem/1418/C
// Time: 9/14/2025, 12:25:11 PM
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
const int MOD = 1000000007, INF = 2e18, N = 2e5 + 1;

int n;
vi a;

int dp[N][2];

int calc(int i, int round){ // round = (0 == me), (1 == my friend).
    if (i >= n) return 0;

    if(dp[i][round] != -1) return dp[i][round];

    if (round == 1) return dp[i][round] = min(calc(i + 1, !round) + (a[i] == 1), calc(i + 2, !round) + (a[i] == 1) + (a[i + 1] == 1));
    return dp[i][round] = min(calc(i + 1, !round), calc(i + 2, !round));
}

void solve() {
    cin >> n;
    a.resize(n + 5, -1);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i <= n; i++){
        for (int round = 0; round < 2; round++){
            dp[i][round] = -1;
        }
    }
    
    cout << calc(0, 1) << "\n";
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