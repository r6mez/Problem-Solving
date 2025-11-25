/*
    One day, I'm gonna grow wings
*/
// D. Locked Out
// URL: https://codeforces.com/problemset/problem/2161/D
// Time: 11/4/2025, 8:35:39 PM
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
    vi a(n);
    vector<vi> idx(n + 2);
    for (int i = 0; i < n; i++) cin >> a[i], idx[a[i]].push_back(i);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = idx[i].size() - 1; j >= 0; j--) {
            if (idx[i + 1].empty()) break;
            if (idx[i + 1].back() > idx[i][j]) ans++, idx[i + 1].pop_back();
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