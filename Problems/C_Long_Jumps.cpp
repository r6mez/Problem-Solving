/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Long Jumps
// URL: https://codeforces.com/problemset/problem/1472/C
// Time: 5/15/2025, 5:18:13 PM
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
    vi a(n + 1); for (int i = 1; i <= n; i++) cin >> a[i];

    vi dp(n + 2);

    int maxScore = 0;
    for(int i = n; i >= 1; i--){
        int nextI = i + a[i];
        dp[i] = a[i] + (nextI <= n ? dp[nextI] : 0);
        maxScore = max(maxScore, dp[i]);
    }
    cout << maxScore << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}