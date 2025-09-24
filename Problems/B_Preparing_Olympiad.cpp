/*
    One day, I'm gonna grow wings
*/
// B. Preparing Olympiad
// URL: https://codeforces.com/problemset/problem/550/B
// Time: 9/19/2025, 6:02:30 PM
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
int n, l, r, x;
vi a;

int calc(int i, int sum, int mn, int mx){
    if(i == n){
        if(mx - mn >= x && (l <= sum && sum <= r)) return 1;
        return 0;
    } 

    return calc(i + 1, sum, mn, mx) + calc(i + 1, sum + a[i], min(mn, a[i]), max(mx, a[i]));
}

void solve() {
    cin >> n >> l >> r >> x;
    a.resize(n);
    cin >> a;
    cout << calc(0, 0, INT_MAX, INT_MIN);
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