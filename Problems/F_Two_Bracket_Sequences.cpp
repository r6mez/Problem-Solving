/*
    One day, I'm gonna grow wings
*/
// F. Two Bracket Sequences
// URL: https://codeforces.com/problemset/problem/1272/F
// Time: 10/15/2025, 9:11:40 PM
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

string s, t;
int n, m; 

string answer = "";
string bestAns = "";
int bestSize = INF;


int dp[205][205][405];


int calc(int i, int j, int b){
    if (i > n || j > m || b < 0 || b > n + m) return INF;
    
    if (dp[i][j][b] != -1) return dp[i][j][b];
    
    if (i == n && j == m) return dp[i][j][b] = b;
    
    int res = INF;
    
    int ni = i + (i < n && s[i] == '(');
    int nj = j + (j < m && t[j] == '(');
    res = min(res, 1 + calc(ni, nj, b + 1));
    
    ni = i + (i < n && s[i] == ')');
    nj = j + (j < m && t[j] == ')');
    res = min(res, 1 + calc(ni, nj, b - 1));

    return dp[i][j][b] = res;
}

string build(int i, int j, int b){
    if (i == n && j == m) return string(b, ')');
    int cur = dp[i][j][b];
    
    int ni = i + (i < n && s[i] == '(');
    int nj = j + (j < m && t[j] == '(');
    
    if (cur == dp[ni][nj][b + 1] + 1)
        return string(1, '(') + build(ni, nj, b + 1);
    
    ni = i + (i < n && s[i] == ')');
    nj = j + (j < m && t[j] == ')');

    if (cur == dp[ni][nj][b - 1] + 1)
        return string(1, ')') + build(ni, nj, b - 1);
    
    return string(); 
}

void solve(){
    memset(dp, -1, sizeof(dp));
    cin >> s >> t;
    n = s.size();
    m = t.size();
    calc(0, 0, 0);
    cout << build(0, 0, 0) << "\n";
}

/*
- state 
    i, j, balance
    i is a pointer for s
    j is a pointer for t
    balance is the difference between cnt('(') and cnt(')')

- basecase
    i == n && j == m && balance > 0 -> good
    i >= n || j >= m || balance < 0 -> not good
    
- transition
    i, j, balance
        -> i + 1, j + 1 
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}