/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Letter Home
// URL: https://codeforces.com/contest/2121/problem/A
// Time: 6/17/2025, 5:36:45 PM
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
    int n, s; cin >> n >> s;
    vi a(n); cin >> a;
    int disL = s - a[0], disR = a[n - 1] - s;
    if(s < a[0]) cout << disR << "\n";
    else if (s > a[n - 1]) cout << disL << "\n";
    else cout << min(disL, disR) * 2 + max(disL, disR) << "\n";
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