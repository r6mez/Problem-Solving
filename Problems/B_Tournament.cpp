/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Tournament
// URL: https://codeforces.com/contest/2123/problem/B
// Time: 7/1/2025, 5:47:07 PM
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
    int n, j, k; cin >> n >> j >> k;
    vi a(n); cin >> a;
    int player = a[j - 1];
    sort(all(a));
    if(k == 1 && a[n - 1] != player) cout << "NO\n";
    else cout << "YES\n";
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