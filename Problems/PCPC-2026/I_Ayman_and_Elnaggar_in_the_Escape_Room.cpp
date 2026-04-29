// I. Ayman and Elnaggar in the Escape Room
// URL: https://codeforces.com/group/Rilx5irOux/contest/640620/problem/I
// Time: 4/27/2026, 9:47:39 PM
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

    vi freq(n + 2, 0);

    int maxMex = 0, mex = 0;
    for (int l = 0, r = 0; r < n; r++) {
        freq[a[r]]++;
        while (freq[a[r]] > 1) {
            freq[a[l]]--;
            if (a[l] < mex) mex = a[l];
            l++;
        }
        while (mex <= n && freq[mex] > 0) mex++;
        maxMex = max(maxMex, mex);
    }

    fill(all(freq), 0);
    int ans = 0, cnt = 0;
    for (int l = 0, r = 0; r < n; r++) {
        freq[a[r]]++;
        if (a[r] < maxMex && freq[a[r]] == 1) cnt++;
        while (freq[a[r]] > 1) {
            if (a[l] < maxMex && freq[a[l]] == 1) cnt--;
            freq[a[l]]--;
            l++;
        }
        if (cnt == maxMex) ans = max(ans, r - l + 1);
    }

    cout << ans << "\n";
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