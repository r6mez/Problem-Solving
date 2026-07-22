// E. Bayt Lahm Workshop Password
// URL: https://codeforces.com/group/zZYq310uLQ/contest/703989/problem/E
// Time: 7/22/2026, 1:10:13 PM
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
    vi coins = {
        1,
        1,
        2,
        6,
        24,
        120,
        720,
        5040,
        40320,
        362880
    };
    
    int n; cin >> n;
    if (n == 1) finish(0);

    vi digits;
    int sum = 0;
    int i = 9;
    while (i >= 0) {
        if (sum + coins[i] <= n) {
            sum += coins[i];
            digits.push_back(i);
            continue;
        }
        i--;
    }

    sort(all(digits));

    for (int i = 1; i < digits.size(); i++){
        if(digits[i] == 1) digits[i] = 0;
        else break;
    }

    for(int d : digits) cout << d;
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