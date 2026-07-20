// G. Six Seven
// URL: https://codeforces.com/group/zZYq310uLQ/contest/702561/problem/G
// Time: 7/11/2026, 7:20:27 PM
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
    int cnt6 = 0, cnt7 = 0;
    for (int x : a) {
        if(x == 6) cnt6++;
        if(x == 7) cnt7++;
    }

    if(cnt6 == 1 && cnt7 == 1) {
        cout << 1 << "\n";
        return;
    }

    if(min(cnt6, cnt7) == n / 2 && cnt6 == cnt7) {
        cout << max(min(cnt6, cnt7) * 2  - 1, 0LL);
        return;
    }

    cout << max(min(cnt6, cnt7) * 2, 0LL);
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