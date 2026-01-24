// C. War Strategy
// URL: https://codeforces.com/contest/2183/problem/C
// Time: 1/23/2026, 2:07:53 PM
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
    int n, m, k; cin >> n >> m >> k;
    
    if (k < n - k + 1) k = n - k + 1;

    int a = 0, b = 0;
    while (true) {
        if (b < n - k && a + (b + 1) + max(a, b + 1) - 1 <= m) ++b;
        if (a < k - 1 && (a + 1) + b + max(a + 1, b) - 1 <= m) ++a;
        else break;
    }
    
    cout << a + b + 1 << endl;
}

/*
9 10
0 0 0 0 1 0 0 0 0
0 0 0 0 1 1 0 0 0 1
0 0 0 1 1 1 0 0 0 2
0 0 0 1 1 2 0 0 0 3
0 0 0 1 2 1 1 0 0 4
0 0 0 3 1 1 1 0 0 5
0 0 2 1 2 1 1 0 0 6
0 1 1 1 3 1 1 0 0 7
0 1 1 1 2 3 1 0 0 8
0 1 1 1 3 1 3 0 0 9
0 1 1 1 4 1 1 2 0 10
0 1 1 1 5 1 1 1 1 11
0 1 1 6 1 1 1 1 1 12
0 1 6 1 2 1 1 1 1 12
0 6 1 1 3 1 1 1 1 13
5 1 1 1 4 1 1 1 1 14
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}