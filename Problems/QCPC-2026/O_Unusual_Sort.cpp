// O. Unusual Sort
// URL: https://codeforces.com/group/Rilx5irOux/contest/636158/problem/O
// Time: 5/4/2026, 2:56:36 PM
#include <algorithm>
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
    int n, x; cin >> n >> x;
    vi a(n); cin >> a;

    vector<vi> sets(x);
    for (int i = 0; i < x; i++) {
        for (int j = i; j < n; j += x) {
            sets[i].push_back(a[j]);
        }
        sort(all(sets[i]));
        for (int j = i, k = 0; j < n && k < sets[i].size(); j += x, k++) {
            a[j] = sets[i][k];
        }
    }

    if(is_sorted(all(a))) cout << "YES\n";
    else cout << "NO\n";
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