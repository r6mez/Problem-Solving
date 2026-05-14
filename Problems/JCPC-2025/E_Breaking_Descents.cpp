// E. Breaking Descents
// URL: https://codeforces.com/group/Rilx5irOux/contest/638270/problem/E
// Time: 5/13/2026, 12:44:42 PM
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
    int cnt = 0;
    int one_diff = 0;
    for(int i = 0; i < n - 1; i++){
        if(a[i] > a[i + 1]) cnt++;
        if(a[i] - a[i + 1] == 1) one_diff++;
    }
    cout << cnt - (one_diff > 0) << "\n";
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