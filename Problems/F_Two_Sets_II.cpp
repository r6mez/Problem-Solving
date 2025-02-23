/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// F - Two Sets II
// URL: https://vjudge.net/contest/694790#problem/F
// Time: 2/23/2025, 6:41:57 PM
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

int sumOfNs(int n){
    return n*(n+1)/2;
}

void Ramez() {
    int n; cin >> n;
    int m = sumOfNs(501);

    vector<vi> dp(n + 2, vi(m + 1, -1));

    function<int(int, int)> countSets = [&](int i, int sum){
        if(i == n + 1){
            if(sum == (sumOfNs(n) - sum) && dp[i][sum] == -1){
                return dp[i][sum] = 1LL;
            } else {
                return dp[i][sum] = 0LL;
            }
        }

        if(dp[i][sum] != -1){
            return dp[i][sum];
        }

        int take = countSets(i + 1, sum + i);
        int leave = countSets(i + 1, sum);

        return dp[i][sum] = (take%MOD + leave%MOD) % MOD;
    };

    cout << countSets(1, 0);
}

/*
NOTES:
1 2 3 4 
0 0 1 
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

