/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// E - Grid Paths
// URL: https://vjudge.net/contest/694790#problem/E
// Time: 2/21/2025, 3:50:48 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void Ramez() {
    int n; cin >> n;
    vector<string> s(n); cin >> s;

    vector<vi> dp(n, vi(n, 0));

    for (int i = 0; i < n; i++){
        if(s[0][i] != '*') dp[0][i] = 1;
        else break;
    }
    
    for (int i = 0; i < n; i++){
        if(s[i][0] != '*') dp[i][0] = 1;
        else break;
    }

    
    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            if(s[i][j] == '*') continue;
            dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    
    cout << dp[n - 1][n - 1];
}   

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

