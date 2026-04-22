// I. Not Common Area
// URL: https://codeforces.com/group/Rilx5irOux/contest/678837/problem/I
// Time: 4/18/2026, 12:10:06 AM
#include <bits/stdc++.h>
#include <utility>
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
    int l1, w1, l2, w2; cin >> l1 >> w1 >> l2 >> w2;
    if(w1 > l1) swap(w1, l1);
    if(w2 > l2) swap(w2, l2);
    if(l2 > l1) swap(l2, l1), swap(w2, w1);
    if(w2 > w1) finish("-1");
    int common = min(l1, l2) * min(w1, w2);
    int total_area = l1 * w1 + l2 * w2 - common;
    int non_common = total_area - common;
    cout << non_common << "\n";
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