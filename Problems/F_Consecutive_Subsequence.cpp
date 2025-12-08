/*
  But there's something kind of fantastic about that.
*/
// F. Consecutive Subsequence
// URL: https://codeforces.com/contest/977/problem/F
// Time: 12/6/2025, 6:37:57 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    map<int, int> dp;

    int answer = 0, last = 0;
    for (int i = 0; i < n; i++){
        int x = a[i];
        dp[x] = dp[x - 1] + 1;
        if(answer < dp[x]){
            answer = dp[x];
            last = x;
        }
    }

    vi result;
    for (int i = n - 1; i >= 0; i--){
        if(a[i] == last) {
            result.push_back(i + 1);
            last--;
        }
    }

    reverse(all(result));  
    cout << result.size() << "\n"; 
    cout << result << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}