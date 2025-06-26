/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Kill Demodogs
// URL: https://codeforces.com/problemset/problem/1731/B
// Time: 6/25/2025, 7:01:56 PM
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
    int n; cin >> n;
    int i = 1, j = 1;
    int cnt = ((((n * (n + 1)) % MOD) * (4 * n - 1)) % MOD * 337) % MOD;
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