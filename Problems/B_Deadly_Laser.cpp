/*
    One day, I'm gonna grow wings
*/
// B. Deadly Laser
// URL: https://codeforces.com/problemset/problem/1721/B
// Time: 9/18/2025, 7:06:52 PM
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
    int n, m, sx, sy, d; cin >> n >> m >> sx >> sy >> d;
    if(min(sx - 1, m - sy) <= d && min(n - sx, sy - 1) <= d){
        cout << "-1\n";
        return;
    }

    cout << n + m - 2 << "\n";
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