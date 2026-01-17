// D. Insolvable Disks
// URL: https://codeforces.com/contest/2180/problem/D
// Time: 12/20/2025, 1:11:59 PM
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
    int pairs = 0, l = 0, r = 2e18;
    for(int i = 0; i < n - 1; i++) {
        int d = a[i + 1] - a[i];
        int nxt = max(0LL, d - r), nxtR = d - l;
        if (nxt < nxtR) l = nxt, r = nxtR, pairs++;
        else l = 0, r = d;
    }
    cout << pairs << endl;
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