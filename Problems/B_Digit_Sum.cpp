/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// B - Digit Sum
// URL: https://vjudge.net/contest/696623#problem/B
// Time: 3/1/2025, 1:41:34 AM
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

// dp[pos][sum][tight] 
int dp[10001][101][2];  
string k; int d; 

int solveDP(int pos, int sum, bool tight) {
    if (pos == k.size()) {
        return (sum % d == 0) ? 1 : 0;
    }

    if (dp[pos][sum][tight] != -1) return dp[pos][sum][tight];
    
    int res = 0;
    int limit = tight ?  (k[pos] - '0') : 9;
    
    for (int digit = 0; digit <= limit; digit++) {
        bool newTight = tight && (digit == limit);
        res = (res + solveDP(pos + 1, (sum + digit)%d, newTight))%MOD ;
    }
    dp[pos][sum][tight] = res;
    return res;
}

void Ramez() {
    cin >> k >> d;
    memset(dp, -1, sizeof(dp));
    cout << ( (solveDP(0, 0, true) - 1) % MOD + MOD ) % MOD << "\n";
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

