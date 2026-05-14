// F. Inscribed triangle in circle
// URL: https://codeforces.com/group/Rilx5irOux/contest/638270/problem/F
// Time: 5/13/2026, 4:05:42 PM
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
    int xa, ya, xg, yg, S;
    cin >> xa >> ya;
    cin >> xg >> yg;
    cin >> S;
    
    int dx = xa - xg;
    int dy = ya - yg;
    double d = sqrt(dx * dx + dy * dy);
    
    double R = sqrt(S);
    
    double ans = ((R - d) * (R - d)) / 2.0;
    
    cout << ans << "\n";
}

/*

*/

signed main() {
    cout << fixed << setprecision(6); 
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}