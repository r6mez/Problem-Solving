// L. Bit
// URL: https://codeforces.com/group/zZYq310uLQ/contest/701118/problem/L
// Time: 7/5/2026, 2:44:07 PM
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
    int n, q; cin >> n >> q;
    unsigned int zero = 0, one = ~0ULL;
    while (n--) {
        int t, a; cin >> t >> a;
        if (t == 1) zero &= a, one &= a;
        if (t == 2) zero |= a, one |= a;
        if (t == 3) zero ^= a, one ^= a;
    }

    while (q--) {
        int r; cin >> r;
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (1LL << i);
            if (bit > r) continue;
            if (zero & bit) continue;
            if ((one & bit) && (res | bit) <= r) {
                res |= bit;
            }
        }
        cout << res << "\n";
    }
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