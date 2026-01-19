// C. Shifted MEX
// URL: https://codeforces.com/contest/2185/problem/C
// Time: 1/19/2026, 12:26:35 PM
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

    sort(all(a));
    a.erase(unique(all(a)), a.end());

    int mxS = 0, currS = 1;
    for (int i = 1; i < a.size(); i++){
        if(a[i] == a[i-1] + 1){
            currS++;
        } else {
            mxS = max(mxS, currS);
            currS = 1;
        }
    }
    cout << max(mxS, currS) << "\n";
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