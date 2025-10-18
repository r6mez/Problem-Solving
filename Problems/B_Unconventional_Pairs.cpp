/*
    One day, I'm gonna grow wings
*/
// B. Unconventional Pairs
// URL: https://codeforces.com/contest/2149/problem/B
// Time: 9/25/2025, 5:40:48 PM
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

    int mx = INT_MIN;
    sort(all(a));

    for (int i = 0; i < n - 1; i+=2){
        mx = max(mx, a[i + 1] - a[i]);
    }
    finish(mx);
}

/*
3 8 9 3 3 2
2 3 3 3 8 9
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}