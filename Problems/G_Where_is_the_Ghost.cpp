/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// G - Where is the Ghost
// URL: https://vjudge.net/contest/694790#problem/G
// Time: 2/23/2025, 7:19:33 PM
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
    vi a(n); cin >> a;

    const int end = 2520; 
    
    vector<int> dp(end + 1, 0);
    dp[1] = 1; // Base case (empty subset has product 1)

    for (int x : a) {
        vector<int> newDP = dp; // Copy previous DP state
        int modX = x % end;

        for (int rem = 0; rem < end; rem++) {
            if (dp[rem]) { 
                int newRem = (rem * modX) % end;
                newDP[newRem] = (newDP[newRem] + dp[rem]) % MOD;
            }
        }
        dp = newDP;
    }

    cout << dp[0] << "\n"; // Count of subsets where product % 2520 == 0
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

