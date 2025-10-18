/*
    One day, I'm gonna grow wings
*/
// B. ShaFeiii's XOR Tournament
// URL: https://codeforces.com/group/1CUdKCvauM/contest/638299/problem/B
// Time: 10/5/2025, 8:06:58 PM
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
    int n, m; cin >> n >> m;
    vi a(n), b(m); cin >> a >> b;

    int ans = 0;
    if (m & 1) {
        for (int i = 0; i < n; i++) {
            ans ^= a[i];
        }
    }
    if (n & 1) {
        for (int i = 0; i < m; i++) {
            ans ^= b[i];
        }
    }
    cout << ans << '\n';
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