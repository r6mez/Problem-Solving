/*
    One day, I'm gonna grow wings
*/
// F. Goblin
// URL: https://codeforces.com/problemset/problem/2106/F
// Time: 10/21/2025, 7:13:19 PM
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
    string s; cin >> s;
    s = " " + s;
    vector<int> top(n + 1, 0), bot(n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            top[i] = bot[i - 1] + 1;
        }
        else {
            top[i] = top[i - 1] + (i - 1);
            bot[i] = bot[i - 1] + (n - i);
        }
        ans = max(ans, max(top[i], bot[i]));
    }
    cout << ans << "\n";
}

/*
- a[i][i] is flipped, otherwise it's the same as s
- he wants the maximum chunk size of adj zeros


000

100
010
001

111
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}