// D. Racing Frogs
// URL: https://codeforces.com/group/Rilx5irOux/contest/678837/problem/D
// Time: 4/21/2026, 10:55:27 PM
#include <bits/stdc++.h>
#include <cstdlib>
#include <numeric>
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
    int a, b, n; cin >> a >> b >> n;
    int d = gcd(abs(b - a), n);
    int t = n / d;
    int pad = (a * t)%n + 1;
    cout << pad << "\n";
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