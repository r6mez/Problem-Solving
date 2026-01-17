// C. The Values You Can Make
// URL: https://codeforces.com/contest/687/problem/C
// Time: 12/8/2025, 4:44:06 PM
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

int n, k;
vi c;
const int N = 505;
bool dp[2][N][N];

void solve() {
    cin >> n >> k;
    c.resize(n); cin >> c;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int now = i % 2;
        int last = 1 - now;
        int x = c[i - 1];
        for (int j = 0; j <= k; j++)
            for (int y = 0; y <= j; y++)
            {
                dp[now][j][y] = dp[last][j][y];
                if (j >= x)
                {
                    dp[now][j][y] |= dp[last][j - x][y];
                    if (y >= x)
                        dp[now][j][y] |= dp[last][j - x][y - x];
                }
            }
    }
    vector <int> res;
    for (int i = 0; i <= k; i++)
        if (dp[n % 2][k][i])
            res.push_back(i);
    cout << res.size() << endl;
    for (int x : res)
        cout << x << " ";
    cout << endl;
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