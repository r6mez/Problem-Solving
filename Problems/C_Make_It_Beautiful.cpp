/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Make It Beautiful
// URL: https://codeforces.com/contest/2118/problem/C
// Time: 6/12/2025, 10:37:51 PM
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
    vi a(n); cin >> a;

    int cnt = 0;

    for (int b = 0; b < 61; b++) {
        for (int i = 0; i < n && (k >= (1LL << b)); i++) {
            if (((a[i] >> b) & 1) == 0) {
                k -= 1LL << b;
                a[i] |= 1LL << b;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cnt += __builtin_popcountll(a[i]);
    }

    cout << cnt << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}