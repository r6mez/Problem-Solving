// E. Decode
// URL: https://codeforces.com/problemset/problem/1996/E
// Time: 2/2/2026, 2:55:06 PM
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
    int n = s.size();

    vi pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (s[i] == '1' ? 1 : -1);
    }

    map<int, int> count;
    int ans = 0;
    
    for (int i = 0; i <= n; i++) {
        int l = count[pre[i]];
        int r = n - i + 1;
        ans = (ans + l * r) % MOD;
        count[pre[i]] += i + 1;
    }

    cout << ans << "\n";
}

/*
for every subsegment
how many subsegments with zeros = ones

I think we can build the answer from smaller segments
if we have a segment with equal zeros and ones x, y
it adds to the answer x * (n - y + 1)
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}