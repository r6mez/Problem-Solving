/*
    I was alone in an empty universe.
    A universe too small and at the same time... too infinite.
*/
// D. Dar al-Hawa: Historic Neighborhood in Jerusalem
// URL: https://codeforces.com/group/o09Gu2FpOx/contest/541493/problem/D
// Time: 7/23/2025, 6:47:05 PM
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

vector<long double> dp(7e3);

void Ramez() {
    long double r, n; cin >> r >> n;  
    if(n >= dp.size()) cout << 0 << "\n";
    else cout << setprecision(8) << fixed << r * dp[n] << "\n";
}

/*
NOTES:

*/

int32_t main() {
    long double ratio = 0.85786438 / 5;
    dp[0] = 1; dp[1] = ratio;
    for (int i = 2; i < dp.size(); i++){
        dp[i] = dp[i - 1] * ratio;
    }
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}