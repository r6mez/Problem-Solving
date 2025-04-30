/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Median Splits
// URL: https://codeforces.com/contest/2103/problem/C
// Time: 4/21/2025, 10:12:04 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void Ramez() {
    int n, k; cin >> n >> k;
    vi a(n + 1), pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + (a[i] <= k) - (a[i] > k);
    }
    vi pref_mi(n, 0);
    vi suf_mi(n + 2, INT_MAX), suf_ma(n + 2, -INT_MAX);
    pref_mi[1] = pref[1];
    for (int i = 2; i <= n - 1; i++) {
        pref_mi[i] = min(pref_mi[i - 1], pref[i]);
    }
    for (int i = n - 1; i >= 1; i--) {
        suf_mi[i] = min(pref[i], suf_mi[i + 1]);
        suf_ma[i] = max(pref[i], suf_ma[i + 1]);
    }

    for (int i = 1; i <= n - 2; i++) {
        if (pref[i] >= 0 && suf_ma[i + 1] >= pref[i]) {
            cout << "YES\n";
            return;
        }
    }
    for (int i = 2; i <= n - 1; i++) {
        if (pref[i] <= pref[n] && pref_mi[i - 1] <= pref[i]) {
            cout << "YES\n";
            return;
        }
    }
    for (int i = 1; i <= n - 2; i++) {
        if (pref[i] >= 0 && suf_mi[i + 1] <= pref[n]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

/*
NOTES:
10 7 | 12 16 3 15 | 6 11
(7, 15, 6) = (6, 7, 15)

10 7 12 16 3 15 6 11



7 11 12 4 9 17

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}