// E. The Collision Protocol
// URL: https://codeforces.com/group/Rilx5irOux/contest/686782/problem/E
// Time: 5/25/2026, 4:43:28 PM
#include <algorithm>
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

int n;
string s;

void solve() {
    cin >> n;
    cin >> s;
    
    int l_surv = 0;
    int current_open = 0; 
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            current_open--;
        } else { 
            current_open++;
        }
        
        if (current_open < 0) {
            l_surv++;
            current_open = 0;
        }
    }

    int r_surv = 0;
    int current_close = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'R') {
            current_close--;
        } else {
            current_close++;
        }
        
        if (current_close < 0) {
            r_surv++;
            current_close = 0;
        }
    }

    int ans = l_surv + r_surv;
    if (ans % 2 != n % 2) {
        ans++;
    }

    cout << ans << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}