/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// B - Coin Combinations I
// URL: https://vjudge.net/contest/694790#problem/B
// Time: 2/21/2025, 12:05:57 AM
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
    int n, x; cin >> n >> x;
    vi c(n); cin >> c;

    vi dp(x + 1, -1);

    auto countWays = [&](int currSum, auto &&fun_ref) -> int {
        if(currSum > x) return 0LL;
        if(currSum == x) return 1LL;
        if(dp[currSum] != -1) return dp[currSum];
        
        int ways = 0;
        for(int coin : c){
            ways = (ways + fun_ref(currSum + coin, fun_ref)) % MOD;
        }
         
        return dp[currSum] = ways;
    };

    int answer = countWays(0, countWays);
    cout << answer << "\n";
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

