// C. Cut It From the Left
// URL: https://codeforces.com/group/Rilx5irOux/contest/643069/problem/C
// Time: 5/2/2026, 11:07:26 PM
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
    string s, t; cin >> s >> t;
    reverse(all(s));
    reverse(all(t));
    int i = 0;
    while (i < s.size() && i < t.size()) {
        if (s[i] == t[i]) i++;
        else break;
    }
    cout << s.size() + t.size() - 2 * i << "\n";
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