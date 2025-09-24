/*
    One day, I'm gonna grow wings
*/
// H - Grid 1
// URL: https://atcoder.jp/contests/dp/tasks/dp_h?lang=en
// Time: 9/13/2025, 2:48:13 PM
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

int n, m;
vector<string> grid;
const int N = 1001;
int dp[N][N];

int calc(int i, int j){
    if(i == n || j == m || grid[i][j] == '#') return 0;
    if(i == n - 1 && j == m - 1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = (calc(i, j + 1)%MOD + calc(i + 1, j)%MOD)%MOD;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    grid.resize(n);
    cin >> grid;
    cout << calc(0, 0);
}

/*
dp[i][j] = number of ways you can get to cell (i, j)
dp[n][m] == 1;
print(dp[0][0]);
dp[i][j] -> dp[i + 1][j] || dp[i][j + 1];
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}