/*
    One day, I'm gonna grow wings
*/
// B. Make Connected
// URL: https://codeforces.com/contest/2161/problem/B
// Time: 11/1/2025, 9:48:59 PM
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
    int n;
    cin >> n;
    int mx1 = INT_MIN, mx2 = INT_MIN, mn1 = INT_MAX, mn2 = INT_MAX, mxx = INT_MIN, mnx = INT_MAX, mxy = INT_MIN, mny = INT_MAX, cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                mx1 = max(mx1, i + j);
                mx2 = max(mx2, i - j);
                mn1 = min(mn1, i + j);
                mn2 = min(mn2, i - j);
                mxx = max(mxx, i);
                mnx = min(mnx, i);
                mxy = max(mxy, j);
                mny = min(mny, j);
                cnt++;
            }
        }
    }
    if (cnt == 0 || mx1 - mn1 <= 1 || mx2 - mn2 <= 1 || ((mxx - mnx) <= 1 && (mxy - mny) <= 1)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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