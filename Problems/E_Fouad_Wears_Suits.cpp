/*
    I was alone in an empty universe.
    A universe too small and at the same time... too infinite.
*/
// E. Fouad Wears Suits
// URL: https://codeforces.com/group/o09Gu2FpOx/contest/541488/problem/E
// Time: 7/23/2025, 6:37:28 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("fouad.in", "r", stdin); }
const int MOD = 1000000007;


void Ramez() {
    int x, y; cin >> x >> y;
    cout << min(x, y) << "\n";
}

/*
NOTES:

*/

int32_t main() {
    UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}