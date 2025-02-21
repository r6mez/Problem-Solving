/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// C - Minimizing Coins
// URL: https://vjudge.net/contest/694790#problem/C
// Time: 2/21/2025, 1:25:50 PM
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
    dp[0] = 0;

    auto minCoins = [&](int amount, auto &&ref_fun) -> int {
        if (dp[amount] != -1) return dp[amount];  
    
        int minCoinsNeeded = INT_MAX;
        for (int coin : c) {
            if(amount - coin >= 0) minCoinsNeeded = min(minCoinsNeeded, ref_fun(amount - coin, ref_fun) + 1LL);
        }
    
        return dp[amount] = minCoinsNeeded;  
    };

    minCoins(x, minCoins);

    if(dp[x] >= INT_MAX){
        cout << -1 << "\n";
    } else {
        cout << dp[x] << "\n";
    }
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

