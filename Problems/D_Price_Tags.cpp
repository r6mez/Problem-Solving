/*
    One day, I'm gonna grow wings
*/
// D. Price Tags
// URL: https://codeforces.com/contest/2144/problem/D
// Time: 9/15/2025, 6:15:42 PM
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
    int n, y; cin >> n >> y;
    vi a(n); cin >> a;
    int mx = *max_element(all(a));
    vi freq(mx + 1), pref(mx + 1);
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    partial_sum(all(freq), pref.begin());

    int bestIncome = LLONG_MIN;

    for (int x = 2; x <= max(mx, 2LL); x++) {
        int newSum = 0, printed = 0;
        
        for (int q = 1; q <= mx; q++) {
            int l = (q - 1) * x + 1, r = min(q * x, mx);
            if (l > mx) break;
            int used = pref[r] - pref[l - 1];
            newSum += q * used;
            printed += max(used - freq[q], 0LL);
        }

        bestIncome = max(bestIncome, newSum - printed * y);
    }

    cout << bestIncome << "\n";
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