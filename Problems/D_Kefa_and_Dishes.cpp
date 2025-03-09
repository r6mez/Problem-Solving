/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// D. Kefa and Dishes
// URL: https://codeforces.com/contest/580/problem/D
// Time: 3/6/2025, 8:08:11 PM
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

int n, m, k;
int dishes[20];
int bonus[20][20];
 
// dp[mask][last] stores the maximum additional satisfaction obtainable starting from state (mask, last).
int dp[1 << 18][20];
 
int rec(int mask, int last) {
    if (__builtin_popcount(mask) == m)
        return 0;
    
    if(dp[mask][last] != -1)
        return dp[mask][last];
    
    int best = 0;
    for (int i = 0; i < n; i++){
        if (!(mask & (1 << i))) {
            int newMask = mask | (1 << i);
            int candidate = dishes[i] + bonus[last][i] + rec(newMask, i);
            best = max(best, candidate);
        }
    }
    dp[mask][last] = best;
    return best;
}
 
void Ramez() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        cin >> dishes[i];
    }
    
    memset(bonus, 0, sizeof(bonus));
    for (int i = 0; i < k; i++){
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        bonus[x][y] = c; 
    }
    
    memset(dp, -1, sizeof(dp));
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        int mask = (1 << i);
        ans = max(ans, dishes[i] + rec(mask, i));
    }
    
    cout << ans << "\n";
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