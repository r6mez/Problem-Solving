// B. Kalculating Damage
// URL: https://codeforces.com/group/zZYq310uLQ/contest/700325/problem/B
// Time: 7/19/2026, 7:41:10 PM
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
    char a, d; cin >> a >> d;
    int p; cin >> p;
    int h; cin >> h;
    int x = max(0LL, (int)(h - p * (a == 'F' && d == 'G' || a == 'G' && d == 'W' || a == 'W' && d == 'F' ? 2 : 0.5)));
    if(x == 0) cout << "Nocaute!";
    else cout << "Sobraram " << x << " pontos de vida!";
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