/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Woodcutters
// URL: https://codeforces.com/problemset/problem/545/C
// Time: 6/6/2025, 6:43:11 PM
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
    vi x(n + 2), h(n + 2); 
    for (int i = 1; i <= n; i++){
        cin >> x[i] >> h[i];
    }

    
    x[0] = LLONG_MIN; x[n + 1] = LLONG_MAX;

    vector<vi> dp(n + 2, vi(2, -1));
    
    function<int(int, int, int)> calc = [&](int i, int last, int cnt) -> int {
        if(i == n + 1) return dp[i][last] = cnt;

        if(~dp[i][last]) return dp[i][last];
        
        int answer = dp[i][last];
      
        if(last == 0 && x[i] - h[i] > x[i - 1]) answer = max(answer, calc(i + 1, 0, cnt + 1));

        if(last == 1 && x[i] - h[i] > x[i - 1] + h[i - 1])  answer = max(answer, calc(i + 1, 0, cnt + 1));

        if(x[i] + h[i] < x[i + 1]) answer = max(answer, calc(i + 1, 1, cnt + 1));

        answer = max(answer, calc(i + 1, 0, cnt));

        return dp[i][last] = answer;
    };
    
    cout << calc(1, 0, 0);
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