/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// Counting Numbers
// URL: https://cses.fi/alon/task/2220
// Time: 2/28/2025, 4:41:09 PM
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


// dp[pos][prev][tight] 
int dp[25][11][2];  
string num;

int solveDP(int pos, int prev, bool tight) {
    if (pos == num.size())
        return 1; // reached the end: one valid way (even if the number is all zeros)
    
    if (dp[pos][prev][tight] != -1)
        return dp[pos][prev][tight];
    
    int res = 0;
    int limit = tight ? (num[pos] - '0') : 9;
    
    for (int d = 0; d <= limit; d++) {
        // If we have already started (prev != 10) then we must avoid repeating the last digit.
        if (prev != 10 && d == prev)
            continue;
        
        bool newTight = tight && (d == limit);
        int newPrev;
        // When not started (prev == 10), if we choose 0 we still haven't started.
        // Otherwise, choosing a nonzero digit starts the number.
        if (prev == 10 && d == 0)
            newPrev = 10; // remain in "not started" state
        else
            newPrev = d;  // update previous digit
        
        res += solveDP(pos + 1, newPrev, newTight);
    }
    dp[pos][prev][tight] = res;
    return res;
}

int count_valid(int x) {
    if (x < 0) return 0;
    num = to_string(x);
    memset(dp, -1, sizeof(dp));
    return solveDP(0, 10, true);
}


void Ramez() {
    int a, b;
    cin >> a >> b;
    cout << count_valid(b) - count_valid(a - 1) << "\n";
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

