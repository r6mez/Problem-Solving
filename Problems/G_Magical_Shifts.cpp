// G. Magical Shifts
// URL: https://codeforces.com/group/4afEIuSpfa/contest/676953/problem/G
// Time: 3/12/2026, 8:37:07 PM
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
    vi a(n + 1), first(n + 1, -1), last(n + 1, -1);
    
    // Record first and last index of each value
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (first[a[i]] == -1) first[a[i]] = i;
        last[a[i]] = i;
    }
    
    // Collect only values that actually appear, in sorted order
    vi val;
    for (int i = 1; i <= n; i++)
        if (first[i] != -1)
            val.push_back(i);
    
    int ans = 1, cur = 1;
    for (int i = 1; i < val.size(); i++) {
        if (last[val[i - 1]] < first[val[i]]) cur++; // chain extends
        else cur = 1; // chain breaks
        ans = max(ans, cur);
    }
    
    cout << val.size() - ans << "\n";
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