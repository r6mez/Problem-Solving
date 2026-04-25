// F. Olive Harvest
// URL: https://codeforces.com/group/Rilx5irOux/contest/640620/problem/F
// Time: 4/25/2026, 8:45:08 PM
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
    
    vi a(n + 1);
    vi sum(n + 1);
    int zeros = 1, ones = 0;;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        sum[i] %= 2;
        if(!sum[i]) zeros++;
        else ones++;
    }

    int answer = zeros * (zeros - 1) / 2 + ones * (ones - 1) / 2;
    cout << answer << "\n";
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