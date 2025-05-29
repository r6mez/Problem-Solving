/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Gifts Unjust Division!
// URL: https://codeforces.com/group/Rilx5irOux/contest/608858/problem/A
// Time: 5/29/2025, 2:45:55 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("gift.in", "r", stdin); }
const int MOD = 1000000007;

void Ramez() {
    int n; cin >> n;
    int c = n / 8, q = n - c;
    cout << c << " " << q << "\n";
}

/*
NOTES:

*/

int32_t main() {
    UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}