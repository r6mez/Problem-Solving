// C. Frog Jumps
// URL: https://codeforces.com/contest/1324/problem/C
// Time: 3/12/2026, 7:15:24 PM
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
    string s; cin >> s;

    vi pos; pos.push_back(0);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'R') pos.push_back(i + 1);
    } pos.push_back(s.size() + 1);
    
    int ans = 0;
    for (int i = 0; i < pos.size() - 1; ++i) {
        ans = max(ans, pos[i + 1] - pos[i]);
    }
    
    cout << ans << endl;
}

/*
it's better to not visit any position twice
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}