/*
    One day, I'm gonna grow wings
*/
// F - LCS
// URL: https://atcoder.jp/contests/dp/tasks/dp_f?lang=en
// Time: 9/13/2025, 1:51:33 PM
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

string a, b;
int n, m;

const int N = 3001; 
int dp[N][N];

int calc(int i, int j){
    if(i == n || j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(a[i] == b[j]) return dp[i][j] = calc(i + 1, j + 1) + 1;
    return dp[i][j] = max(calc(i + 1, j), calc(i, j + 1));
}

string answer = "";

void build(int i, int j){
    if(i == n || j == m) return;
    if(a[i] == b[j]) {
        answer += a[i];
        build(i + 1, j + 1);
    } else {
        if(calc(i + 1, j) > calc(i, j + 1)){
            build(i + 1, j);
        } else {
            build(i, j + 1);
        }
    }
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    n = a.size(); m = b.size();
    build(0, 0);
    cout << answer;
}

/*
dp[i][j] = length of LCS between the first i characters of string X and the first j characters of string Y.
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}